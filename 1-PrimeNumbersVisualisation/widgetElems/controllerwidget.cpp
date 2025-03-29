#include "controllerwidget.h"

ControllerWidget::ControllerWidget(QWidget *parent)
{
    this->setParent(parent);

    btnUp = new QPushButton("Up", this);

    btnReturn = new QPushButton("Return", this);

    layout = new QVBoxLayout(this);

    layout->addWidget(btnUp);

    layout->addWidget(btnReturn);

    layout->setSpacing(1);

    layout->setContentsMargins(20, 20, 20, 20);
}

QPushButton *ControllerWidget::getBtnUp() const{
    return btnUp;
}

QPushButton *ControllerWidget::getBtnReturn() const{
    return btnReturn;
}



