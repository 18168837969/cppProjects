#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include <AppConfig.h>
#include <log4cplusImp.h>
#include "AppConfig.h"
#include "AppHelper.h"
int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(resources);
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    QDesktopWidget* desktop = QApplication::desktop();
    QRect screenGeometry = desktop->screenGeometry();
    AppConfig::DeskHeight = screenGeometry.height();
    AppConfig::DeskWidth = screenGeometry.width();
    if (!AppConfig::ReadConfig() || !MyLog->Init())
    {
        return -1;
    }
    QSharedMemory shared_memory("BrokenProjectYinchuan");
    if (!shared_memory.create(1))
    {
        AppHelper::showMessageBoxError(QStringLiteral("程序已经运行，系统将自动关闭!"));
        return 1;
    }
    QObject::connect(&a, &QApplication::aboutToQuit, [&]() {
        Q_CLEANUP_RESOURCE(resources);
        });
    MainWindow w;
    w.show();
    return a.exec();
}
