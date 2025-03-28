#include "custombutton.h"

CustomButton::CustomButton(QString text, QWidget *parent)
{
    this->setText(text);
    this->setParent(parent);

    this->_isActive = false;

    QObject::connect(this, &CustomButton::signalToChangeColor, this, &CustomButton::changeColor);
}

void CustomButton::changeColor()
{
    if(_isActive)
        this->setStyleSheet("background-color: " + GlobVal::hexColorToSimpleColor(Qt::cyan) + ";");
    else
        this->setStyleSheet("background-color: " + GlobVal::hexColorToSimpleColor(Qt::white) + ";");
}

void CustomButton::changeIsActive()
{
    _isActive = _isActive ? false : true;
    emit signalToChangeColor();
}
