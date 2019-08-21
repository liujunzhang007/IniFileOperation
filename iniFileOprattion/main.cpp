#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "FileOpration.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    FileOpration *fileIO = new FileOpration();
    fileIO->fileCreate();
    fileIO->fileWrite();
    fileIO->fileRead();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

//    QScopedPointer<FileOpration> current(new FileOpration());
//    engine.rootContext().setContextProperty("FileOpration", current.value());
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}


//大叔大婶发生的非官方的啊飒飒是打发

// asdasdasdadadfgdfdfgdfgdfgdg
// dsasfdsfsdfsdfs