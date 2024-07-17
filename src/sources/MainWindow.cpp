#include "MainWindow.h"
MainWindow::MainWindow(QWidget* parent)
	: QWidget(parent), m_checkBox(new QtMaterialCheckBox)

{
	ui.setupUi(this);
	AppHelper::setStyleSheet(this,":/styles/style/MainWindow.qss");
	this->setWindowFlags(Qt::FramelessWindowHint);
	this->showFullScreen();
	initWidgets();

	initConnects();
	m_timer1000->start(1000);
		
}

MainWindow::~MainWindow()
{}

void MainWindow::initWidgets()
{
	m_tabs = new QtMaterialTabs(ui.frame);
	m_tabs->addTab("单晶炉控制");
	m_tabs->addTab("气体/真空");
	m_tabs->addTab("趋势图");
	m_tabs->addTab("SOP");
	m_tabs->addTab("生长记录");
	m_tabs->addTab("辅助功能");
	m_tabs->addTab("变量显示");
	m_tabs->addTab("自动选项");
	m_tabs->setUseThemeColors(false);

	m_mainControl = new mainControl(this);
	ui.stackedWidget->removeWidget(ui.page1);
	ui.stackedWidget->removeWidget(ui.page2);
	delete ui.page1;
	delete ui.page2;
	ui.stackedWidget->addWidget(m_mainControl);

	ui.frame->setFixedHeight(85);
	ui.labelStatus->setFixedHeight(80);
	ui.topStatusWidget->setFixedHeight(80);
	ui.topEmergencyBtnWidegt->setFixedHeight(80);
	//alarm
	ui.layoutWidget->resize(ui.layoutWidget->parentWidget()->size());
	ui.verticalLayout->setStretchFactor(ui.stackedWidget, 1);
	ui.gridLayout->setContentsMargins(5, 0, 0, 5);
	//tab
	QVBoxLayout* qvboxlayout = new QVBoxLayout(ui.frame);
	qvboxlayout->setContentsMargins(0, 0, 0, 0);
	qvboxlayout->addWidget(m_tabs);
	qvboxlayout->setAlignment(m_tabs, Qt::AlignTop);
	ui.stackedWidget->setCurrentIndex(0);
	m_timer1000 = new QTimer(this);
	ui.labelTime->setText(QTime::currentTime().toString("HH:mm:ss"));

	QVBoxLayout* qvBox = new QVBoxLayout(ui.topEmergencyBtnWidegt);
	qvBox->setMargin(0);
	qvBox->setContentsMargins(0,0,0,0);
	emergency = UiHelper::GetInstance()->GetLightBlueBtn(
		ui.topEmergencyBtnWidegt,"紧急保护按钮", ui.topEmergencyBtnWidegt->width(),
		ui.topEmergencyBtnWidegt->height());
	emergency->setBackgroundColor(GlobalColors::KayexWarningYellow);
	emergency->setForegroundColor(GlobalColors::KayexWhite);
	emergency->setCornerRadius(0);
	qvBox->addWidget(emergency);
	m_tabs->setBackgroundColor(GlobalColors::KayexDarkBlue);

}

void MainWindow::initConnects()
{

	connect(m_timer1000, &QTimer::timeout,this, [this]() {
		ui.labelTime->setText(QTime::currentTime().toString("HH:mm:ss"));
		});
	connect(m_tabs, &QtMaterialTabs::currentChanged, this, [this](int index) {
		ui.stackedWidget->setCurrentIndex(index);
		});
}





