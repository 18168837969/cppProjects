#pragma once
#include <QtCore>
#include <QApplication>
#include <QDesktopWidget>
#include "frmmessagebox.h"
class AppHelper :public QObject
{
public:
    //设置开机启动
    static void setAutoRunWithSystem(bool isAutoRun, const QString& appName,
        const QString& appPath)
    {
        QSettings* reg = new QSettings(
            "HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
            QSettings::NativeFormat);

        if (isAutoRun) {
            reg->setValue(appName, appPath);
        }
        else {
            reg->setValue(appName, "");
        }
    }

    //设置皮肤样式
    static bool setStyle(const QString& styleName)
    {
        QFile file(QString("%1").arg(styleName));
        if (!file.open(QFile::ReadOnly))
        {
            return false;
        }
        QString css = QLatin1String(file.readAll());

        file.close();

        qApp->setStyleSheet(css);

        return true;
    }

    //加载中文字符
    static void setChinese(const QString& fileName)
    {
        QTranslator* translator = new QTranslator(qApp);
        translator->load(QString("%1").arg(fileName));
        qApp->installTranslator(translator);
    }

    //仅确认按钮
    static void showMessageBoxInfo(const QString& info)
    {
        frmMessageBox* msg = new frmMessageBox;
        msg->SetMessage(info, 0);
        msg->exec();
    }

    //询问框，确认和取消按钮
    static int showMessageBoxQusetion(const QString& info)
    {
        frmMessageBox* msg = new frmMessageBox;
        msg->SetMessage(info, 1);
        return msg->exec();
    }

    //错误框,确认和取消按钮
    static void showMessageBoxError(const QString& info)
    {
        frmMessageBox* msg = new frmMessageBox;
        msg->SetMessage(info, 2);
        msg->exec();
    }

    //延时
    static void sleep(const int& sec)
    {
        QTime dieTime = QTime::currentTime().addMSecs(sec);
        while (QTime::currentTime() < dieTime) {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
    }

    //窗体居中显示
    static void FormInCenter(QWidget* frm, int deskWidth, int deskHeigth)
    {
        int frmX = frm->width();
        int frmY = frm->height();
        QPoint movePoint(deskWidth / 2 - frmX / 2, deskHeigth / 2 - frmY / 2);
        frm->move(movePoint);
    }

    //文件夹是否存在
    static bool FolderIsExist(QString strFolder)
    {
        QDir tempFolder(strFolder);
        return tempFolder.exists();
    }

    //文件是否存在
    static bool FileIsExist(QString strFile)
    {
        QFile tempFile(strFile);
        return tempFile.exists();
    }

    //判断是否是IP地址
    static bool isIpAddress(const QString& ip)
    {
        QRegExp regExp("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)");
        return regExp.exactMatch(ip);
    }

    

    //延时
    static void Sleep(int sec)
    {
        QTime dieTime = QTime::currentTime().addMSecs(sec);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }




};
