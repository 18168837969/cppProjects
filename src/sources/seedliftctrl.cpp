#include "seedliftctrl.h"
#include<opencv2/opencv.hpp>
SeedLiftCtrl::SeedLiftCtrl(QWidget *parent)
	: BaseWidget(parent)
	, ui(new Ui::SeedLiftCtrlClass())
{
	ui->setupUi(this);
	cv::Mat mat;
	
}

SeedLiftCtrl::~SeedLiftCtrl()
{
	delete ui;
}


