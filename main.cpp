#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "client.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Register Client class as QML type
    qmlRegisterType<Client>("ChatClient", 1, 0, "Client");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/message_2/Main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
