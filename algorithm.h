#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <QCryptographicHash>
#include <QString>
#include <QDebug>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/crypto.h>
#include <openssl/rsa.h>
#include <zlib.h>


class Algorithm
{
public:
    static unsigned char s2c_public_key[140];
    static unsigned char c2s_private_key[609];
    static unsigned char s2c_private_key[608];
    static unsigned char c2s_public_key[140];
    static std::string aes_key;
    static std::string aes_iv;
public:
    static QString qtMD5(const QString& text){
        QByteArray hash = QCryptographicHash::hash(text.toLatin1(),QCryptographicHash::Md5);
        return hash.toHex();
    }
    static QString MD5(const QString& text){
        int ret = 0;
        QString result;
        EVP_MD_CTX* ctx = EVP_MD_CTX_new();//1 创建上下文
        do{
            if(ctx==NULL)break;
            ret = EVP_MD_CTX_init(ctx);//2 初始化上下文
            if(ret==0)break;
            ret = EVP_DigestInit_ex(ctx,EVP_md5(),NULL);//3 指定算法参数
            if(ret==0)break;
            QByteArray data = text.toLatin1();
            ret = EVP_DigestUpdate(ctx,data.data(),data.size());//4 填入数据
            if(ret==0)break;
            QByteArray out;
            out.resize(64);
            memset(out.data(),0,out.size());
            unsigned int len = 0;
            ret = EVP_DigestFinal(ctx,(unsigned char*)out.data(),&len);//5 获取结果
            if(ret==0)break;
            out.resize(len);
            result = out.toHex();
        }while(false);
        EVP_MD_CTX_free(ctx);//6 清理上下文
        return result;
    }

    static QByteArray AES256Encrypt(const QString& text,std::string& key,std::string& iv){
        EVP_CIPHER_CTX* chipher = EVP_CIPHER_CTX_new();
        QByteArray out,data;
        do{//初始化+指定算法参数2+3
            int ret = 0;
            ret = EVP_CipherInit_ex(chipher,EVP_aes_256_cbc(),NULL,
                                    (unsigned char*)key.data(),
                                    (unsigned char*)iv.data(),1);
            if(ret==0)break;

            int outlen=0,temp=0;
            data = text.toLatin1();
            out.resize(((data.size()+31)/32)*32);
            ret = EVP_EncryptUpdate(chipher,
                                    (unsigned char*)out.data(),&outlen,
                                    (unsigned char*)data.data(),(int)data.size());
            if(ret==0)break;
            ret = EVP_EncryptFinal_ex(chipher,(unsigned char*)out.data()+outlen,&temp);
            if(ret==0)break;
            outlen+=temp;
            out.resize(outlen);
        }while(false);
        EVP_CIPHER_CTX_free(chipher);
        return out;
    }
    static QByteArray AES256Decrypt(const QByteArray& data,std::string& key,std::string& iv){
        EVP_CIPHER_CTX* chipher = EVP_CIPHER_CTX_new();
        QByteArray out;
        do{
            int ret = 0;
            ret = EVP_CipherInit_ex(chipher,EVP_aes_256_cbc(),NULL,
                                    (unsigned char*)key.data(),
                                    (unsigned char*)iv.data(),0);
            if(ret==0)break;
            int outlen=0,temp=0;
            out.resize(((data.size()+31)/32)*32);
            ret = EVP_DecryptUpdate(chipher,(unsigned char*)out.data(),&outlen,(unsigned char*)data.data(),(int)data.size());
            if(ret==0)break;
            ret = EVP_DecryptFinal_ex(chipher,(unsigned char*)out.data()+outlen,&temp);
            if(ret==0)break;
            outlen+=temp;
            out.resize(outlen);
        }while(false);
        EVP_CIPHER_CTX_free(chipher);
        return out;
    }

    static int GenRSAKey(QByteArray& pubKey,QByteArray& priKey){
        int ret = 0;
        EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, NULL);
        do{
            if(ctx==nullptr){
                ret = -1;
                break;
            }
            ret = EVP_PKEY_keygen_init(ctx);
            if(ret==0){
                ret = -2;
                break;
            }
            if(EVP_PKEY_CTX_set_rsa_keygen_bits(ctx,1024)<=0){
                ret = -3;
                break;
            }
            EVP_PKEY* pkey = NULL;
            if(EVP_PKEY_keygen(ctx,&pkey)<=0){
                ret = -4;break;
            }
            int len = i2d_PublicKey(pkey,NULL);//获取密钥的长度
            pubKey.resize(len);
            unsigned char* data = (unsigned char*)pubKey.data();
            len = i2d_PublicKey(pkey, &data);
            qDebug()<<"pubkey len:"<<len;

            len = i2d_PrivateKey(pkey,NULL);//获取密钥的长度
            priKey.resize(len);
            data = (unsigned char*)priKey.data();
            len = i2d_PrivateKey(pkey, &data);
            qDebug()<<"priKey len:"<<len;

            EVP_PKEY_free(pkey);
        }while(false);
        if(ret!=0){
            ERR_print_errors_fp(stderr);
        }
        EVP_PKEY_CTX_free(ctx);
        return ret;
    }

    static QByteArray RSAEncrypt(const QByteArray& text,QByteArray& key)
    {
        QByteArray out;
        const unsigned char* pp = (const unsigned char*)key.data();
        EVP_PKEY* ekey = d2i_PublicKey(EVP_PKEY_RSA,NULL,&pp,key.size());
        EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new(ekey,NULL);
        int ret = 0;
        do{
            if(ctx==NULL){
                ret = -1;
                break;
            }
            ret = EVP_PKEY_encrypt_init(ctx);
            if(ret==0){
                ret = -2;
                break;
            }
            ret = EVP_PKEY_CTX_set_rsa_padding(ctx,RSA_NO_PADDING);
            if(ret==0){
                ret = -3;
                break;
            }
            size_t len = 0;
            ret = EVP_PKEY_encrypt(ctx,NULL,&len,(const unsigned char*)text.data(),text.size());
            if(ret==0){
                ret = -4;
                break;
            }
            out.resize(len);
            if((size_t)text.size()<len){//如果输入的长度小于输出的长度，则输入长度进行补齐，方便解密的时候对齐长度
                QByteArray d(len,0);
                memcpy(d.data(),text.data(),text.size());
                ret = EVP_PKEY_encrypt(ctx,(unsigned char*)out.data(),&len,(const unsigned char*)d.data(),d.size());
            }else{
                ret = EVP_PKEY_encrypt(ctx,(unsigned char*)out.data(),&len,(const unsigned char*)text.data(),text.size());
            }
        }while(false);
        if(ret!=0){
            ERR_print_errors_fp(stderr);
        }
        if(ctx != NULL)EVP_PKEY_CTX_free(ctx);
        EVP_PKEY_free(ekey);
        return out;
    }

    static QByteArray RSADecrypt(QByteArray& data,QByteArray& key)
    {
        QByteArray out;
        const unsigned char* pp = (const unsigned char*)key.data();
        EVP_PKEY* ekey = d2i_PrivateKey(EVP_PKEY_RSA,NULL,&pp,key.size());
        EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new(ekey,NULL);
        int ret = 0;
        do{
            if(ctx==NULL){
                ret = -1;
                break;
            }
            ret = EVP_PKEY_decrypt_init(ctx);
            if(ret==0){
                ret = -2;
                break;
            }
            ret = EVP_PKEY_CTX_set_rsa_padding(ctx,RSA_NO_PADDING);
            if(ret==0){
                ret = -3;
                break;
            }
            size_t len = 0;
            ret = EVP_PKEY_decrypt(ctx,NULL,&len,(const unsigned char*)data.data(),data.size());
            if(ret==0){
                ret = -4;
                break;
            }
            out.resize(len);
            ret = EVP_PKEY_decrypt(ctx,(unsigned char*)out.data(),&len,(const unsigned char*)data.data(),data.size());
        }while(false);
        if(ret!=0){
            ERR_print_errors_fp(stderr);
        }
        if(ctx != NULL)EVP_PKEY_CTX_free(ctx);
        EVP_PKEY_free(ekey);
        return out.data();
    }

    static std::string Base64Encode(QByteArray& data){
        size_t blocksize = data.size()*8/6+3;
        size_t maxsize = blocksize+5;
        std::string out;
        out.resize(maxsize);
        int ret = 0;
        EVP_ENCODE_CTX* ctx = EVP_ENCODE_CTX_new();//1
        if(ctx==NULL)return std::string();
        EVP_EncodeInit(ctx);//2
        int outlen=0,total=0;
        ret = EVP_EncodeUpdate(ctx,(unsigned char*)out.data(),&outlen,(const unsigned char*)data.data(),(int)data.size());//3
        if(ret<=0){
            EVP_ENCODE_CTX_free(ctx);
            ERR_print_errors_fp(stderr);
            return std::string();
        }
        total = outlen;
        outlen = 0;
        qDebug()<<"total:"<<total;
        EVP_EncodeFinal(ctx,(unsigned char*)out.data()+total,&outlen);//4
        total += outlen;
        qDebug()<<"out:"<<out.size();
        qDebug()<<"out:"<<out.data();
        out.resize(total-1);
        qDebug()<<"outlen:"<<outlen;
        qDebug()<<"blocksize:"<<blocksize;
        qDebug()<<"total:"<<total;
        qDebug()<<"out"<<out.data();
        EVP_ENCODE_CTX_free(ctx);//5
        return out;
    }

    static QByteArray Base64Decode(std::string& data){
        if(data.size()<4)return QByteArray();
        qDebug()<<"data.size():"<<data.size();
        int ret = 0,outlen=0,total=0,blocksize=(int)data.size()*6/8;
        QByteArray out;
        out.resize(blocksize,0);
        EVP_ENCODE_CTX* ctx = EVP_ENCODE_CTX_new();//1
        if(ctx==NULL)return QByteArray();
        EVP_DecodeInit(ctx);//2
        ret = EVP_DecodeUpdate(ctx,(unsigned char*)out.data(),&outlen,(const unsigned char*)data.data(),(int)data.size());
        if(ret<0){
            qDebug()<<"*ret = "<<ret;
            qDebug()<<"*code "<<ERR_peek_last_error()<<" msg "<<ERR_reason_error_string(ERR_peek_last_error());
            EVP_ENCODE_CTX_free(ctx);
            ERR_print_errors_fp(stdout);
            return QByteArray();
        }
        total = outlen;
        ret = EVP_DecodeFinal(ctx,(unsigned char*)out.data()+total,&outlen);
        if(ret<0){
            qDebug()<<"ret = "<<ret;
            qDebug()<<"code "<<ERR_peek_last_error()<<" msg "<<ERR_reason_error_string(ERR_peek_last_error());
            ERR_print_errors_fp(stdout);
            EVP_ENCODE_CTX_free(ctx);
            return QByteArray();
        }
        total += outlen;
        out.resize(total);
        EVP_ENCODE_CTX_free(ctx);
        return out;
    }

    enum Level{
        DEFAULT_LEVEL = Z_DEFAULT_COMPRESSION,//默认压缩比例
        NO_COMPRESSION,// = Z_NO_COMPRESSION,//无压缩
        BEST_SPEED_LEVEL,// = Z_BEST_SPEED,//速度有限
        COMPRESSION_1_LEVEL,
        COMPRESSION_2_LEVEL,
        COMPRESSION_3_LEVEL,
        COMPRESSION_4_LEVEL,
        COMPRESSION_5_LEVEL,
        COMPRESSION_6_LEVEL,
        COMPRESSION_7_LEVEL,
        BEST_COMPRESSION_LEVEL = Z_BEST_COMPRESSION  //最高压缩比
    };

    static QByteArray Compress(QByteArray& data,Level level){
        QByteArray out;
        uLongf len = (uLongf)data.size()*3;
        out.resize(len);
        int ret = compress2((Bytef*)out.data(),&len,(const Bytef*)data.data(),(uLong)data.size(),level);
        qDebug()<<"out size:"<<len;
        if(ret!=Z_OK){
            qDebug()<<"ret = "<<ret;
            len=0;
        }
        out.resize(len);
        return out;
    }

    static QByteArray Uncompress(QByteArray& data){
        QByteArray out;
        uLongf len=0,used;
        int ret = Z_OK;
        do{
            used = (uLongf)data.size();
            len += used;
            out.resize(len);
            ret = uncompress2((Bytef*)out.data(),&len,(const Bytef*)data.data(),&used);
            if(ret==Z_MEM_ERROR){
                qDebug()<<"内存不足！！"<<" len:"<<len<<" used:"<<used;
                return QByteArray();
            }
            if(ret==Z_DATA_ERROR){
                qDebug()<<"数据格式错误，无法解压！！！size: "<<data.size()<<" data:"<<data;
                return QByteArray();
            }
        }while(ret!=Z_OK);
        out.resize(len);
        return out;
    }

    template<typename T>
    static QByteArray int2Array(const T& d){
        size_t sz = sizeof(T);
        QByteArray bytes;
        bytes.resize(sz);
        quint64 mask = 0xFF;
        for(size_t i=0;i<sz;i++)
        {
            mask<<=(8*i);
            bytes[i] = (char)((mask&d)>>(8*i));
        }
        return bytes;
    }

    template<typename T>
    static T Array2int(const QByteArray& bytes){
        T data = 0;
        size_t sz = sizeof(T);
        for(size_t i=0;i<sz;i++){
            data |= ((bytes[i]&0xFF)<<(i*8));
        }
        return data;
    }
};

#define I16ToBytes(d) Algorithm::int2Array<short>(d)
#define I32ToBytes(d) Algorithm::int2Array<int>(d)
#define AESKEY Algorithm::aes_key
#define AESIV Algorithm::aes_iv

#endif // ALGORITHM_H
