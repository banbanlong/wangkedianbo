#include "enetwork.h"
#include "algorithm.h"

class EPacket{
public:
    EPacket()
        : m_cmd(-1)
    {}
    EPacket(int cmd,const QByteArray& data)
        : m_cmd(cmd)
        , m_data(data)
    {}
    EPacket(const EPacket& pack){
        m_cmd = pack.m_cmd;
        m_data = pack.m_data;
    }
    EPacket& operator=(const EPacket& pack){
        if(this!=&pack){
            m_cmd = pack.m_cmd;
            m_data = pack.m_data;
        }
        return *this;
    }
public:
    operator QByteArray(){
        QByteArray ret;
        qDebug().nospace()<<__FILE__<<"("<<__LINE__<<"):<"<<__FUNCTION__<<">:";
        //编码 0xFE 0xFF 包长度4字节 命令4字节 json数据（长度不定）
        ret += I16ToBytes((short)0xFFFE);// FE FF
        ret += I32ToBytes(4+m_data.size());
        ret += I32ToBytes(m_cmd);
        ret += m_data;
        return ret;
    }
    static EPacket from(const QByteArray& data, quint64& used){
        EPacket pack;
        used = 0;
        if(data.size()<10) return pack;
        qsizetype i = 0;
        for(;i+1<data.size();i++){
            if((data[i]==(char)0xFE) && (data[i+1]==(char)0xFF)){
                i+=2;
                break;
            }
        }
        if(i+1>=data.size())return pack;//没有找到包头，无法解析
        if(data.size()-i<8)return pack;//剩余数据不足
        unsigned size = 0;
        memcpy(&size,data.data()+i,sizeof(unsigned));
        i+=4;
        if(data.size()<size+i)return pack;//剩余数据不足
        memcpy(&pack.m_cmd,data.data()+i,sizeof(int));
        i+=4;
        if(size>4){
            pack.m_data = QByteArray::fromRawData(data.data()+i,size-4);
            i += size-4;
        }
        used = i;
        return pack;
    }
public:
    int m_cmd;
    QByteArray m_data;
};

ENetwork::ENetwork()
    : m_port(-1)
{
    connect(&m_sock,&QAbstractSocket::errorOccurred,this,&ENetwork::error);
    connect(&m_sock,&QAbstractSocket::connected,this,&ENetwork::connected);
    connect(&m_sock,&QIODevice::readyRead,this,&ENetwork::onReadyRead);
}

void ENetwork::start()
{
    if(m_port==-1){
        emit error(-1);
        return;
    }
    //1.1.1.1  localhost
    if(m_host.size()<7){
        emit error(-2);
        return;
    }
    m_sock.connectToHost(m_host, m_port);
}

void ENetwork::send(int cmd, const QJsonObject &d)
{
    QJsonObject data = d;
    qDebug().nospace()<<__FILE__<<"("<<__LINE__<<"):<"<<__FUNCTION__<<">:"<<data;
    qDebug().nospace()<<__FILE__<<"("<<__LINE__<<"):<"<<__FUNCTION__<<">:"<<cmd;
    //在此处进行加解密 针对的是data
    QJsonDocument doc;
    doc.setObject(data);
    QByteArray rsakey((char*)Algorithm::c2s_public_key,sizeof(Algorithm::c2s_public_key));
    EPacket pack;
    pack.m_cmd = cmd;

    if(cmd==0){//连接（不是登录）
        //RSA  ==> AES
        QByteArray out = doc.toJson();
        pack.m_data = Algorithm::RSAEncrypt(out,rsakey);
    }else if(cmd == 1){//登录
        //AES 要算一下账号和密码的md5，不要传明文 将account password 签名化
        data["account"] = Algorithm::MD5(data["account"].toString());
        data["password"] = Algorithm::MD5(data["password"].toString());
        doc.setObject(data);
        pack.m_data = Algorithm::AES256Encrypt(doc.toJson(),AESKEY,AESIV);
    }else{//其他命令
        //AES
        pack.m_data = Algorithm::AES256Encrypt(doc.toJson(),AESKEY,AESIV);
    }
    qDebug().nospace()<<__FILE__<<"("<<__LINE__<<"):<"<<__FUNCTION__<<">:send:"<<(QByteArray)pack;
    m_sock.write(pack);
}

void ENetwork::onReadyRead()
{
    QByteArray data = m_sock.readAll();
    qDebug().nospace()<<__FILE__<<"("<<__LINE__<<"):<"<<__FUNCTION__<<">:data="<<data;
    m_buffer += data;
    quint64 used = 0;
    EPacket pack = EPacket::from(m_buffer,used);
    qDebug().nospace()<<__FILE__<<"("<<__LINE__<<"):<"<<__FUNCTION__<<">:used="<<used;
    if(used>0){
        QByteArray rsa_key = QByteArray::fromRawData((char*)Algorithm::s2c_private_key,sizeof(Algorithm::s2c_private_key));
        if(pack.m_cmd==0){//RSA
            pack.m_data = Algorithm::RSADecrypt(pack.m_data,rsa_key);
        }else{
            pack.m_data = Algorithm::AES256Decrypt(pack.m_data,AESKEY,AESIV);
        }
        m_buffer.remove(0, used);
        QJsonDocument doc=QJsonDocument::fromJson(pack.m_data);
        QJsonObject root = doc.object();
        if(pack.m_cmd==0){
            AESKEY = root["aeskey"].toString().toStdString();
            qDebug().nospace()<<__FILE__<<"("<<__LINE__<<"):<"<<__FUNCTION__<<">:aeskey="<<AESKEY.c_str();
            root = QJsonObject();//清理掉密钥信息，防止UI层获取
        }
        emit receive(pack.m_cmd,root);
    }
}
