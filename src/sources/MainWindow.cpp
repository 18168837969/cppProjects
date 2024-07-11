#include "MainWindow.h"
#include <QMessageBox>
#include "log4cplusImp.h"
#include <qdebug.h>
#include <qboxlayout.h>
#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include <QtWidgets/QStackedWidget>
#include <qtmaterialtabs.h>
#include "AppConfig.h"
bool listResources1(const QString& path)
{
	bool result = false;
	QDir dir(path);
	if (!dir.exists()) {
		qDebug() << "Directory does not exist:" << path;
		result = false;
	}

	QFileInfoList list = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
	for (const QFileInfo& fileInfo : list) {
		if (fileInfo.isDir()) {
			if (listResources1(fileInfo.filePath()))
			{
				return true;
			}
		}
		else if (!fileInfo.filePath().startsWith(":/qt-project") &&
			!fileInfo.filePath().startsWith(":/images") &&
			!fileInfo.filePath().startsWith(":/qgradient") &&
			!fileInfo.filePath().startsWith(":/qpdf")
			)
		{
			qDebug() << "--------------------------------------" << fileInfo.filePath();
			qDebug() << "Loaded resource:" << fileInfo.filePath();
			result = true;
			return result;
		}
		else if (
			fileInfo.filePath().startsWith(":/images")

			)
		{
			int aa = 1;

		}
	}
	return result;
}
MainWindow::MainWindow(QWidget* parent)
	: QWidget(parent), m_checkBox(new QtMaterialCheckBox)

{
	ui.setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint);
	this->showFullScreen();

	initWidgets();
	ui.frame->setFixedHeight(85);
	ui.verticalLayout->setStretchFactor(ui.stackedWidget, 1);
	QVBoxLayout* qvboxlayout = new QVBoxLayout(ui.frame);
	qvboxlayout->setContentsMargins(0, 0, 0, 0);
	qvboxlayout->addWidget(m_tabs);
	m_tabs->addTab("单晶炉控制");
	m_tabs->addTab("气体/真空");
	m_tabs->addTab("趋势图");
	m_tabs->addTab("SOP");
	m_tabs->addTab("生长记录");
	m_tabs->addTab("辅助功能");
	m_tabs->addTab("变量显示");
	m_tabs->addTab("自动选项");
	m_tabs->addTab("自动选项");
	m_tabs->setUseThemeColors(false);
	m_tabs->setBackgroundColor(GlobalColors::KayexDarkBlue);

	ui.stackedWidget->setCurrentIndex(0);


	connect(m_tabs, &QtMaterialTabs::currentChanged, this, &MainWindow::tabIndexChanged);
		//connect(m_button, &QPushButton::clicked, this, &MainWindow::pbHello_clicked);
}

MainWindow::~MainWindow()
{}

void MainWindow::initWidgets()
{
	m_tabs = new QtMaterialTabs(ui.frame);
	m_mainControl = new mainControl(this);
	ui.stackedWidget->removeWidget(ui.page1);
	ui.stackedWidget->removeWidget(ui.page2);
	delete ui.page1;
	delete ui.page2;
	ui.stackedWidget->addWidget(m_mainControl);
	QLabel* la = new QLabel("aa",this);
	ui.stackedWidget->addWidget(la);
}

void MainWindow::tabIndexChanged(int index)
{
	ui.stackedWidget->setCurrentIndex(index);
}

void  MainWindow::pbHello_clicked()
{

	/*QMessageBox::information(this, "title","你好 world");
	LOG_ERROR(L"你好");
	LOG_INFO(L"你好");*/

}