#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>

class TcpClient : public QObject
{
public:
    /**
     * @brief Constructor de la clase TcpClient
     */
    TcpClient();
    /**
     * @brief conecta el cliente con el servidor
     */
    void Connect();
    /**
     * @brief envia el mensaje al servidor
     */
    void sendMessage(QString);
    /**
     * @brief obtiene el mensaje enviado por el servidor
     */
    QString getMessage();
private:
    QTcpSocket *mSocket;
    QString text;
};

#endif // TCPCLIENT_H
