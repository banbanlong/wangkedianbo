#ifndef ALGORITHM_H
#define ALGORITHM_H
#include<QCryptographicHash>
#include<QDebug>
#include<openssl/evp.h>
#include<openssl/err.h>
#include<openssl/crypto.h>
#include<openssl/rsa.h>
#include<zlib.h>
class Algorithm
{
public:
    static QString qtMD5(const QString& text){
        QByteArray hash = QCryptographicHash::hash(text.toLatin1(), QCryptographicHash::Md5);
        return hash.toHex();
    }
    static QString MD5(const QString& text){
        int ret = 0;
        QString result;
        EVP_MD_CTX* ctx = EVP_MD_CTX_new();  // 1 创建上下文
        do {
            if (ctx == NULL) break;

            ret = EVP_MD_CTX_init(ctx);  // 2 初始化上下文
            if (ret == 0) break;

            ret = EVP_DigestInit_ex(ctx, EVP_md5(), NULL);  // 3 指定算法
            if (ret == 0) break;

            QByteArray data = text.toLatin1();  // 4 数据准备
            ret = EVP_DigestUpdate(ctx, data.data(), data.size());  // 填入数据
            if (ret == 0) break;

            QByteArray out;
            out.resize(64);  // 5 分配输出缓冲区
            memset(out.data(), 0, out.size());

            unsigned int len = 0;
            ret = EVP_DigestFinal(ctx, (unsigned char*)out.data(), &len);  // 6 计算摘要
            if (ret == 0) break;
            out.resize(len);
            result = out.toHex();  // 转为16进制字符串
        } while (false);

        EVP_MD_CTX_free(ctx);  // 7 清理上下文
        return result;
    }
    static QByteArray AES256Encrypt(const QString& text,const std::string& key,const std::string& iv){
        //chipher不要使用静态成员、成员或者静态变量 否则多线程的情况下，可能出现意外
        EVP_CIPHER_CTX* chipher = EVP_CIPHER_CTX_new();
        QByteArray out,data;
        do{//初始化+指定算法参数2+3
            int ret = 0;
            ret = EVP_CipherInit_ex(chipher,//上下文
                                    EVP_aes_256_cbc(),NULL,//密码类型
                                    (unsigned char*)key.data(),//主密码
                                    (unsigned char*)iv.data(),//从密码
                                    1);//1 加密 0 解密
            if(ret==0)break;
            int outlen=0,temp=0;
            data = text.toLatin1();
            out.resize(((data.size()+31)/32)*32);
            ret = EVP_EncryptUpdate(chipher,
                                    (unsigned char*)out.data(),&outlen,
                                    (unsigned char*)data.data(),
                                    (int)data.size());
            if(ret==0)break;
            ret = EVP_EncryptFinal_ex(chipher,(unsigned
                                                char*)out.data()+outlen,&temp);
            if(ret==0)break;
            outlen+=temp;
            out.resize(outlen);
        }while(false);
        EVP_CIPHER_CTX_free(chipher);
        return out;
    }
    static QString AES256Decrypt(const QByteArray& data,const std::string& key,const std::string& iv){
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
            ret = EVP_DecryptUpdate(chipher,(unsigned
                                              char*)out.data(),&outlen,(unsigned char*)data.data(),
                                    (int)data.size());
            if(ret==0)break;
            ret = EVP_DecryptFinal_ex(chipher,(unsigned
                                                char*)out.data()+outlen,&temp);
            if(ret==0)break;
            outlen+=temp;
            out.resize(outlen);
        }while(false);
        EVP_CIPHER_CTX_free(chipher);
        return out;
    }
    static int GenRSAKey(QByteArray& pubkey,QByteArray& prikey)
    {
        pubkey.resize(1024 * 1024 * 2);
        prikey.resize(1024 * 1024 * 2);
        //1、创建RSA公钥加密上下文,参数1为算法类型
        EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, NULL);
        if (!ctx)
        {
            ERR_print_errors_fp(stderr);
            EVP_PKEY_CTX_free(ctx);
            return -1;
        }
        //2、初始化密钥对生成上下文
        int ret = EVP_PKEY_keygen_init(ctx);
        if (!ret)
        {
            ERR_print_errors_fp(stderr);
            EVP_PKEY_CTX_free(ctx);
            return -2;
        }
        //设置参数，RSA的密钥位数2048位
        if (EVP_PKEY_CTX_set_rsa_keygen_bits(ctx, 1024) <= 0)
        {
            ERR_print_errors_fp(stderr);
            EVP_PKEY_CTX_free(ctx);
            return -3;
        }
        //4、密钥生成
        EVP_PKEY* pkey = NULL;
        //内部有malloc申请的空间
        if (EVP_PKEY_keygen(ctx, &pkey) <= 0)
        {
            ERR_print_errors_fp(stderr);
            EVP_PKEY_CTX_free(ctx);
            return -4;
        }
        int len = i2d_PublicKey(pkey, NULL);
        pubkey.resize(len);
        unsigned char* data = (unsigned char*)pubkey.data();
        len = i2d_PublicKey(pkey, &data);
        printf("pub ret = %d\r\n", len);
        len = i2d_PrivateKey(pkey, NULL);
        prikey.resize(len);
        data = (unsigned char*)prikey.data();
        len = i2d_PrivateKey(pkey, &data);
        printf("pri ret = %d\r\n", len);
        //释放资源
        EVP_PKEY_CTX_free(ctx);
        EVP_PKEY_free(pkey);
        return 0;
    }
    static QByteArray RSAEncrypt(const QString& data, const QByteArray& key)
    {
        QByteArray out;
        size_t outLen = 0;

        const unsigned char* pp = (const unsigned char*)key.data();
        EVP_PKEY* pubKey = d2i_PublicKey(EVP_PKEY_RSA, NULL, &pp, key.size());
        if (!pubKey) return out;

        EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new(pubKey, NULL);
        if (!ctx) {
            EVP_PKEY_free(pubKey);
            return out;
        }

        if (EVP_PKEY_encrypt_init(ctx) <= 0 ||
            EVP_PKEY_CTX_set_rsa_padding(ctx, RSA_PKCS1_PADDING) <= 0)
        {
            EVP_PKEY_free(pubKey);
            EVP_PKEY_CTX_free(ctx);
            return out;
        }

        QByteArray inData = data.toUtf8();
        if (EVP_PKEY_encrypt(ctx, NULL, &outLen, (const unsigned char*)inData.data(), inData.size()) <= 0)
            return out;

        out.resize(outLen);
        if (EVP_PKEY_encrypt(ctx, (unsigned char*)out.data(), &outLen, (const unsigned char*)inData.data(), inData.size()) <= 0)
            return QByteArray();

        out.resize(outLen);
        EVP_PKEY_CTX_free(ctx);
        EVP_PKEY_free(pubKey);
        return out;
    }

    static QString RSADecrypt(const QByteArray& data, const QByteArray& key)
    {
        QByteArray out;
        size_t outLen = 0;

        const unsigned char* pp = (const unsigned char*)key.data();
        EVP_PKEY* priKey = d2i_PrivateKey(EVP_PKEY_RSA, NULL, &pp, key.size());
        if (!priKey) return QString();

        EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new(priKey, NULL);
        if (!ctx) {
            EVP_PKEY_free(priKey);
            return QString();
        }

        if (EVP_PKEY_decrypt_init(ctx) <= 0 ||
            EVP_PKEY_CTX_set_rsa_padding(ctx, RSA_PKCS1_PADDING) <= 0)
        {
            EVP_PKEY_CTX_free(ctx);
            EVP_PKEY_free(priKey);
            return QString();
        }

        if (EVP_PKEY_decrypt(ctx, NULL, &outLen, (const unsigned char*)data.data(), data.size()) <= 0)
            return QString();

        out.resize(outLen);
        if (EVP_PKEY_decrypt(ctx, (unsigned char*)out.data(), &outLen, (const unsigned char*)data.data(), data.size()) <= 0)
            return QString();

        out.resize(outLen);
        EVP_PKEY_CTX_free(ctx);
        EVP_PKEY_free(priKey);
        return QString::fromUtf8(out);
    }
    static QString Base64Encode(const QByteArray& data)
    {
        int ret = 0;
        QByteArray out;
        size_t blocksize = data.size() * 8 / 6 + 3;
        out.resize(blocksize,0);
        // 创建数据结构
        EVP_ENCODE_CTX* e_ctx = EVP_ENCODE_CTX_new();
        if (e_ctx == NULL)return QString();
        // 初始化数据结构
        EVP_EncodeInit(e_ctx);
        int outl = 0, total = 0;
        ret = EVP_EncodeUpdate(e_ctx, (unsigned char*)out.data(), &outl,
                               (unsigned char*)data.data(), (int)data.size());
        if (ret <= 0) {
            EVP_ENCODE_CTX_free(e_ctx);
            return QString();
        }
        total += outl;
        // 必须在编码操作结束时调用。它将处理ctx对象中剩余的任何部分数据块。
        EVP_EncodeFinal(e_ctx, (unsigned char*)out.data() + total, &outl);
        total += outl;
        out.resize(total);
        EVP_ENCODE_CTX_free(e_ctx);
        return QString(out);
    }
    static QByteArray Base64Decode(const QString& data)
    {
        QByteArray out;
        if (data.isEmpty() || data.size() < 4)
            return QByteArray();

        QByteArray base64data = data.toUtf8();
        int outl = 0, total = 0;
        int blocksize = base64data.size() * 3 / 4 + 1;
        out.resize(blocksize, 0);

        EVP_ENCODE_CTX* d_ctx = EVP_ENCODE_CTX_new();
        if (!d_ctx)
            return QByteArray();

        EVP_DecodeInit(d_ctx);

        if (EVP_DecodeUpdate(d_ctx,
                             (unsigned char*)out.data(), &outl,
                             (const unsigned char*)base64data.data(), base64data.size()) == -1)
        {
            EVP_ENCODE_CTX_free(d_ctx);
            return QByteArray();
        }
        total += outl;

        if (EVP_DecodeFinal(d_ctx,
                            (unsigned char*)out.data() + total, &outl) == -1)
        {
            EVP_ENCODE_CTX_free(d_ctx);
            return QByteArray();
        }
        total += outl;

        EVP_ENCODE_CTX_free(d_ctx);
        out.resize(total);
        return out;
    }
    enum Level {
        DEFAULT_LEVEL = Z_DEFAULT_COMPRESSION,     // 默认压缩比例
        NO_COMPRESSION,                            // = Z_NO_COMPRESSION，无压缩
        BEST_SPEED_LEVEL,                          // = Z_BEST_SPEED，速度有限
        COMPRESSION_1_LEVEL,
        COMPRESSION_2_LEVEL,
        COMPRESSION_3_LEVEL,
        COMPRESSION_4_LEVEL,
        COMPRESSION_5_LEVEL,
        COMPRESSION_6_LEVEL,
        COMPRESSION_7_LEVEL,
        BEST_COMPRESSION_LEVEL = Z_BEST_COMPRESSION // 最高压缩比
    };

    static QByteArray Compress(QByteArray& data,Level level){
        QByteArray out;
        uLongf len = (uLongf)(data.size()*3);
        out.resize(len);
        int ret = compress2((Bytef*)out.data(),&len,(const Bytef*)data.data(),(uLong)data.size(),(int)level);
        //qDebug()<<"out size = "<<len;
        if(ret!=Z_OK)return QByteArray();
        //qDebug()<<"out = "<<out;
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
            if(ret == Z_MEM_ERROR)return QByteArray();
            if(ret == Z_DATA_ERROR){
                qDebug()<<"数据格式错误，无法解压！";
                return QByteArray();
            }
        }while (ret!=Z_OK);
        out.resize(len);
        return out;
    }
};

#endif // ALGORITHM_H
