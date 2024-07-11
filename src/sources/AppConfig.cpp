#include "AppConfig.h"
#include "qdir.h"
#include "AppHelper.h"
QString AppConfig::AppPath = "";
QString AppConfig::DbType = QStringLiteral("QSQLITE");
QString AppConfig::DbUserName = "";
QString AppConfig::DbPwd = "";
QString AppConfig::DbHost = "";
QString AppConfig::DbName = "";
QString AppConfig::SoftTitle = QStringLiteral("mes对接");
QString AppConfig::SoftVersion = QStringLiteral("V1.0");
QString AppConfig::CompanyName = QStringLiteral("连城凯科斯科技有限公司");
int AppConfig::DeskWidth = 1920;
int AppConfig::DeskHeigth = 1080;

AppConfig::AppConfig()
{

}
void InitResources() {
	//AppConfig::KayexDarkBlue = QColor("#ffebee");
}
AppConfig::~AppConfig()
{
}
bool AppConfig::ReadConfig()
{
	InitResources();
	AppConfig::AppPath = QCoreApplication::applicationDirPath();
	QDir::setCurrent(AppConfig::AppPath);
	QString fileName = AppConfig::AppPath + "/config.ini";
	if (!AppHelper::FileIsExist(fileName)) {
		AppHelper::showMessageBoxError("缺少配置文件config.ini");
		return false;
	}
	QSettings* set = new QSettings(fileName, QSettings::IniFormat);
	set->setIniCodec("UTF-8");
	set->beginGroup("AppConfig");
	AppConfig::DbName = set->value("DbName").toString();
	AppConfig::SoftTitle = set->value("SoftTitle").toString();
	AppConfig::SoftVersion = set->value("SoftVersion").toString();
	AppConfig::CompanyName = set->value("CompanyName").toString();
	set->endGroup();
	return true;
}