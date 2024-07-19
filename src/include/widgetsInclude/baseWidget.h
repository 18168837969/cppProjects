#pragma once

#include "ui_maincontrol.h"
#include "pch.h"
 class BaseWidget:public QWidget
{
     Q_OBJECT
public:
    explicit  BaseWidget(QWidget* parent = nullptr) :QWidget(parent)
    {
    }
    ~BaseWidget() {

    }
signals:
    void widgetDoubleClicked();
protected:
    void paintEvent(QPaintEvent* event) override {
        QStyleOption opt;
        opt.init(this);
        QPainter p(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    }
    void mouseDoubleClickEvent(QMouseEvent* event) override {
        if (event->button() == Qt::LeftButton) {
            emit widgetDoubleClicked();
        }
    }


};


