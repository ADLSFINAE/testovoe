#include "generalwidget.h"

GeneralWidget::GeneralWidget(QWidget *parent)
    :QWidget(parent)
{
    this->setGeometry(GlobVal::generalWidgetGeometry);

    controllerWidget = new ControllerWidget(this);

    inputWidget = new InputWidget(this);

    layout = new QHBoxLayout(this);

    layout->addWidget(inputWidget);

    layout->addWidget(controllerWidget);

    layout->setSpacing(20);

    layout->setContentsMargins(15, 15, 15, 15);

    layout->setStretch(0, 1);

    layout->setStretch(1, 2);

}
