#include "ImgLabel.h"

ImgLabel::ImgLabel(QWidget* parent):QLabel(parent)
{
}

ImgLabel::~ImgLabel()
{
}

void ImgLabel::mouseDoubleClickEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        emit labelDoubleClicked();
    }
}
