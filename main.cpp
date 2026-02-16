#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QLocale>
#include <QTranslator>

//入口函数
int main(int argc, char *argv[])
{
    //qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));//

    QGuiApplication app(argc, argv);//app 主应用

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "ENetClassClient_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    //qml的引擎
    QQmlApplicationEngine engine;
    // main.qml在此处指定
    const QUrl url(u"qrc:/ENetClassClient/main.qml"_qs);
    //const QUrl url(u"qrc:/ENetClassClient/EPlayerWindow.qml"_qs);

    //连接qml的信号和c++的槽函数
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
                         if (!obj && url == objUrl)
                             QCoreApplication::exit(-1);
                     }, Qt::QueuedConnection);

    //设置数据库的路径
    engine.setOfflineStoragePath(".");
    //在下一行之前，手动注册C++类和模块
    //这里指定启动qml，并加载
    engine.load(url);
    //连接qml对象和C++的信号与槽，需从此行才能开始

    return app.exec();
}
