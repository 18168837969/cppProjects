#pragma once

#include <QWidget>
#include "ui_ImageCtrl.h"
#include "baseWidget.h"
QT_BEGIN_NAMESPACE
namespace Ui { class ImageCtrlClass; };
QT_END_NAMESPACE

class ImageCtrl : public BaseWidget
{
	Q_OBJECT

public:
	ImageCtrl(QWidget *parent = nullptr);
	~ImageCtrl();

private:
	Ui::ImageCtrlClass *ui;
};
