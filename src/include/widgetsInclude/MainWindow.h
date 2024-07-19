#pragma once

#include <QtWidgets/QWidget>
#include <qtmaterialtabs.h>
#include "pch.h"
#include "mainControl.h"
#include "ui_MainWindow.h"

class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();
private:
	void initWidgets();
	void initConnects();


private slots:

private:
	Ui::MainWindowClass ui;
	QtMaterialTabs*  m_tabs;
	QtMaterialCheckable*  m_checkBox;
	QtMaterialFlatButton*  m_button;
	mainControl* m_mainControl;
	QTimer* m_timer1000;
	QtMaterialFlatButton* emergency;
};
