#include "maincontrol.h"
#include "ui_maincontrol.h"

mainControl::mainControl(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::mainControl)
{
    ui->setupUi(this);
    QHBoxLayout* topHbox = new QHBoxLayout(ui->topWidget);
    QHBoxLayout* bottomHbox = new QHBoxLayout(ui->bottomWidget);
    QHBoxLayout* midHbox = new QHBoxLayout(ui->midWidget);
    topHbox->setMargin(0);
    bottomHbox->setMargin(0);
    topHbox->setContentsMargins(10,5,10,5);
    bottomHbox->setContentsMargins(10,5,10,5);
    topHbox->setSpacing(10);
    bottomHbox->setSpacing(10);
    int singleButtonWidth = AppConfig::DeskWidth / 10;
    int singleButtonHeight = singleButtonWidth/2;
    QString className = metaObject()->className();
    for (const auto& key : mainCtrlBtnMap.keys()) {
        mainCtrlStruct s = mainCtrlBtnMap.value(key);
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
    


}
void mainControl::ctrlBtnClicked(bool isChecked) {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button && !button->isChecked()) {
        button->setChecked(true);
    }
    else if (button && button->isChecked())
    {
        if (_lastActiveBtn)
        {
            _lastActiveBtn->setChecked(false);
        }
        _lastActiveBtn = button;
    }
}

mainControl::~mainControl()
{
    delete ui;
}
