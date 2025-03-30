#include "infowidget.h"

InfoWidget::InfoWidget(QString nameOfLine, QWidget *parent)
{
    this->setParent(parent);

    typeLabel = new QLabel(nameOfLine, this);

    integerValueLabel = new QLabel("int", this);

    hexValueLabel = new QLabel("hex", this);

    layout = new QHBoxLayout(this);
    layout->addWidget(typeLabel);
    layout->addWidget(integerValueLabel);
    layout->addWidget(hexValueLabel);

    layout->setSpacing(10);

}
