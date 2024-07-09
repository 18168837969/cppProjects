#include "QtCmake.h"
#include <QMessageBox>
QtCmake::QtCmake(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    connect(ui.pbHello, &QPushButton::clicked, this, &QtCmake::pbHello_clicked);
}

QtCmake::~QtCmake()
{}
void  QtCmake::pbHello_clicked()
{
    QMessageBox::information(this, QStringLiteral("title"),QStringLiteral("hello world"));
}