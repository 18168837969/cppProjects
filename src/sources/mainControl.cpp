#include "maincontrol.h"
mainControl::mainControl(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::mainControl)
{
    ui->setupUi(this);
    AppHelper::setStyleSheet(this, ":/styles/style/mainControl.qss");
    QHBoxLayout* topHbox = new QHBoxLayout(ui->topWidget);
    QHBoxLayout* bottomHbox = new QHBoxLayout(ui->bottomWidget);
    QHBoxLayout* midHbox = new QHBoxLayout(ui->midWidget);
    midLeftSW = new QStackedWidget(ui->midWidget);
    midRightSW = new QStackedWidget(ui->midWidget);
    seedLiftCtrl = new SeedLiftCtrl(midLeftSW);
    imageCtrl = new ImageCtrl(midRightSW);
    variablesWidget = new VariablesWidget(midRightSW);
    midHbox->addWidget(midLeftSW);
    midHbox->addWidget(midRightSW);
    midHbox->setSpacing(200);
    midHbox->setContentsMargins(0, 5, 5, 5);
    midHbox->setStretch(0, 1);
    midHbox->setStretch(1, 1);

    topHbox->setMargin(0);
    bottomHbox->setMargin(0);
    topHbox->setContentsMargins(10,5,10,5);
    bottomHbox->setContentsMargins(10,5,10,5);
    topHbox->setSpacing(10);
    bottomHbox->setSpacing(10);

    //init checkedbutton
    int singleButtonWidth = AppConfig::DeskWidth / 10;
    int singleButtonHeight = singleButtonWidth/2;
    QString className = metaObject()->className();
    for (const auto& key : mainCtrlBtnMap.keys()) {
        mainCtrlStruct& s = mainCtrlBtnMap[key];
        QtMaterialFlatButton* m_button;
        if (s.pos == 0)
        {
            m_button = 
           UiHelper::GetInstance()->GetLightBlueBtn(ui->topWidget,s.name, singleButtonWidth, singleButtonHeight,GlobalColors::KayexErrorRed);
            topHbox->addWidget(m_button);
        }
        else {
            m_button =
                UiHelper::GetInstance()->GetLightBlueBtn(ui->topWidget, s.name, singleButtonWidth, singleButtonHeight, GlobalColors::KayexErrorRed);
            bottomHbox->addWidget(m_button);
        }
        s.ctrlBtn = m_button;
        m_button->RegisterMutex(className);

    }
    mainCtrlBtnMap[SeedLift].ctrlBtn->setChecked(true);
    midLeftSW->addWidget(seedLiftCtrl);
    midRightSW->addWidget(variablesWidget);
    midRightSW->addWidget(imageCtrl);
    connect(variablesWidget, &BaseWidget::widgetDoubleClicked, this, [&]() {
        midRightSW->setCurrentIndex(1);
        });
    
}


mainControl::~mainControl()
{
    delete ui;
}
