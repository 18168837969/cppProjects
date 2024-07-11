#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include <AppConfig.h>
#include <log4cplusImp.h>
#include "AppConfig.h"
#include "AppHelper.h"
int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(resources);
    QApplication a(argc, argv);

    a.setStyleSheet("QWidget { margin: 0px; padding: 0px; }");
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
        delete MyLog;
        Q_CLEANUP_RESOURCE(resources);
        });
    MainWindow w;
    w.show();
    return a.exec();
}
