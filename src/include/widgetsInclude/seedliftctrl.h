#pragma once


#include "ui_seedliftctrl.h"
#include "baseWidget.h"

class SeedLiftCtrl : public BaseWidget
{
	Q_OBJECT

public:
	SeedLiftCtrl(QWidget *parent = nullptr);
	~SeedLiftCtrl();

private:
	Ui::SeedLiftCtrlClass *ui;
};
