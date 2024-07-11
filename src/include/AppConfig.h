#pragma once
#include <qstring.h>
#include <qcolor.h>
namespace GlobalColors {
	const QColor KayexDarkBlue("#0000ff");
	const QColor KayexHoverDarkBlue("#0000ff");
	const QColor KayexLightBlue("#2034B2");
	const QColor KayexHoverLightBlue("#4169E1");
	const QColor KayexBackBlue("#000084");

	const QColor KayexErrorRed("#ff0000");
	const QColor KayexWarningYellow("#ffff00");
	const QColor KayexGray("#c0c0c0");

	const QColor KayexGreen("#00ff00");
	const QColor KayexLightGreen("#8fbc8b");
	const QColor KayexPurple("#c000c0");
	const QColor VariableColor("#00bcd4");
}
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
	static int DeskHeigth;

public:
	AppConfig();
	~AppConfig();
	static bool ReadConfig();

private:

};




