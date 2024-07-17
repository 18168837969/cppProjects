#pragma once
#include <qstring.h>


class AppConfig
{
public:
	static QString DbName;
	static QString DbType;
	static QString DbUserName;
	static QString DbPwd;
	static QString DbHost;
	static QString AppPath;
	static QString SoftTitle;
	static QString	SoftVersion;
	static QString	CompanyName;
	static int DeskWidth;
	static int DeskHeight;

public:
	AppConfig();
	~AppConfig();
	static bool ReadConfig();

private:

};




