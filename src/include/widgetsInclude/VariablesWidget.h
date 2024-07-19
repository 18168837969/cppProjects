#pragma once
#include "baseWidget.h"
#include  "ui_VariablesWidget.h"
class VariablesWidget : public BaseWidget
{
	Q_OBJECT

public:
	explicit VariablesWidget(QWidget* parent = nullptr);
	~VariablesWidget();

private:
	Ui::VariablesWidget* ui;
};