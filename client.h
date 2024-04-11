#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QObject>
#include <QString>

class Client : public QTcpSocket
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);
    Q_INVOKABLE void sendMessage(const QString &message);
    Q_INVOKABLE QString readString();
signals:
    void messageReceived(const QString& message);
private:
    QString currentMessage;
    QList<QString> messagesList;
private slots:
    void onReadyRead();
};

#endif // CLIENT_H
