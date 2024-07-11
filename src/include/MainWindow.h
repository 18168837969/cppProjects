#pragma once

#include <QtWidgets/QWidget>
#include "ui_MainWindow.h"
#include <qtmaterialcheckbox.h>
#include <qtmaterialflatbutton.h>
#include <qtmaterialtabs.h>
#include "mainControl.h"
class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();
private:
	void initWidgets();

private slots:
	void  pbHello_clicked();
	void tabIndexChanged(int);
private:
	Ui::MainWindowClass ui;
	QtMaterialTabs*  m_tabs;
	QtMaterialCheckable*  m_checkBox;
	QtMaterialFlatButton*  m_button;
	mainControl* m_mainControl;
};
