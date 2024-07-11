#pragma once
#include <QWidget>

namespace Ui {
    class mainControl;
}

class mainControl : public QWidget
{
    Q_OBJECT

public:
    explicit mainControl(QWidget* parent = nullptr);
    ~mainControl();

private:
    Ui::mainControl* ui;
};