#ifndef ENETWORK_H
#define ENETWORK_H

#include <QQuickItem>
#include <QJsonObject>
#include <QJsonDocument>
#include <QTcpSocket>

class ENetwork : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString host READ host WRITE setHost NOTIFY hostChanged)
    Q_PROPERTY(int port READ port WRITE setPort NOTIFY portChanged)
    QML_ELEMENT
public:
    QString host()const{return m_host;}
    void setHost(const QString& host){m_host = host;}
    int port()const{return m_port;}
    void setPort(int port){m_port = port;}
public:
    ENetwork();
public:
    Q_INVOKABLE void start();
    Q_INVOKABLE void send(int cmd, const QJsonObject& data);
public slots:
    void onReadyRead();
private:
    QString m_host;
    int m_port;
    QTcpSocket m_sock;
    QByteArray m_buffer;
signals:
    void receive(int cmd, const QJsonObject& data);
    void error(int err);
    void hostChanged();
    void portChanged();
    void connected();
};

#endif // ENETWORK_H
