#include "UiHelper.h"
UiHelper::UiHelper()
{

}

UiHelper::~UiHelper()
{
}

QtMaterialFlatButton* UiHelper::GetLightBlueBtn(QWidget* parent,const QString& text, int wid, int height,const QColor& checkedColor)
{
    QtMaterialFlatButton* m_button = new QtMaterialFlatButton(parent);
    m_button->setUseThemeColors(false);
    m_button->setBackgroundColor(GlobalColors::KayexLightBlue);
    m_button->setForegroundColor(GlobalColors::KayexWhite);
    m_button->setFixedHeight(height);
    m_button->setFixedWidth(wid);
    m_button->setOverlayStyle(Material::TintedOverlay);
    m_button->setBackgroundMode(Qt::OpaqueMode);
    m_button->setHaloVisible(false);
    m_button->setRippleStyle(Material::PositionedRipple);
    m_button->setTextAlignment(Qt::AlignHCenter);
    m_button->setCornerRadius(3);
    m_button->setBaseOpacity(0.15);
    m_button->setFontSize(20);
    m_button->setText(text);
    if (checkedColor.isValid())
    {
        m_button->setCheckedColor(checkedColor);
    }
    return m_button;
  }

