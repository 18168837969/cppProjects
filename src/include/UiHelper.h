#pragma once
#include "AppConfig.h"
#include "AppHelper.h"
#include "Singleton.h"
#include "Global.h"
#include <qdebug.h>
#include <qboxlayout.h>
#include <qtmaterialcheckbox.h>
#include <qtmaterialflatbutton.h>
#include "qstackedwidget.h"
class UiHelper :public Singleton<UiHelper>
{
public:
	UiHelper();
	~UiHelper();
	QtMaterialFlatButton* GetLightBlueBtn(QWidget* parent, const QString& text, int wid, int height,const QColor& checkedColor = QColor());



};

