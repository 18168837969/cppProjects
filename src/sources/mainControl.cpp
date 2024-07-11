#include "maincontrol.h"
#include "ui_maincontrol.h"

mainControl::mainControl(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::mainControl)
{
    ui->setupUi(this);
}

mainControl::~mainControl()
{
    delete ui;
}
