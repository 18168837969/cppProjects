#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtCmake.h"

class QtCmake : public QWidget
{
	Q_OBJECT

public:
	QtCmake(QWidget* parent = nullptr);
	~QtCmake();
private slots:
	void  pbHello_clicked();
private:
	Ui::QtCmakeClass ui;
};
