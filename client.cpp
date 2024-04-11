#include "client.h"
#include <QDataStream>

Client::Client(QObject *parent) : QTcpSocket(parent)
{
    connect(this, &QTcpSocket::readyRead, this, &Client::onReadyRead);
    connectToHost("127.0.0.1", 1234); // Измените IP и порт, чтобы соответствовать настройкам вашего сервера
}

void Client::sendMessage(const QString &message)
{
    QByteArray utf8Message = message.toUtf8();
    QDataStream out(this);
    out.setVersion(QDataStream::Qt_5_15);
    out << utf8Message;
}

QString Client::readString()
{
    QString message = currentMessage;
    currentMessage.clear();
    return message;
}



void Client::onReadyRead()
{
    QDataStream in(this);
    in.setVersion(QDataStream::Qt_5_15);
    while (!in.atEnd()) {
        QByteArray messageData;
        in >> messageData;
        QString message = QString::fromUtf8(messageData);
        emit messageReceived(message); // Emit a signal to notify the QML interface about the received message
    }
}




