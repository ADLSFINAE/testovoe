#include "generalwidget.h"

GeneralWidget::GeneralWidget(QWidget *parent)
    :QWidget(parent)
{
    this->setGeometry(GlobVal::generalWidgetGeometry);

    _controllerWidget = new ControllerWidget(this);

    _inputWidget = new InputWidget(this);

    _layout = new QHBoxLayout(this);

    _layout->addWidget(_inputWidget);

    _layout->addWidget(_controllerWidget);

    _layout->setSpacing(20);

    _layout->setContentsMargins(15, 15, 15, 15);

    _layout->setStretch(0, 1);

    _layout->setStretch(1, 2);

}

ControllerWidget *GeneralWidget::getControllerWidget() const{
    return _controllerWidget;
}

InputWidget *GeneralWidget::getInputWidget() const{
    return _inputWidget;
}
