#include "ImageCtrl.h"

ImageCtrl::ImageCtrl(QWidget *parent)
	: BaseWidget(parent)
	, ui(new Ui::ImageCtrlClass())
{
	ui->setupUi(this);
	QPixmap pixmap("D:/2/等径/2024-03-05 05-47-22-430.bmp");
	//ui->lbImg->setPixmap(pixmap);
	//connect(ui->lbImg,&QLabel::do)
}

ImageCtrl::~ImageCtrl()
{
	delete ui;
}
