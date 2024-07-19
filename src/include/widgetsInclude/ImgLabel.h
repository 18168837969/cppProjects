#pragma once
#include "pch.h"
class ImgLabel:public QLabel
{
	Q_OBJECT
public:
	explicit  ImgLabel(QWidget* parent = nullptr);
	~ImgLabel();

signals:
	void labelDoubleClicked();
protected:
	void mouseDoubleClickEvent(QMouseEvent* event) override;
};

