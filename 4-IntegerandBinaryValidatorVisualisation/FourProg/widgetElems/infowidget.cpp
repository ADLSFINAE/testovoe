#include "infowidget.h"

InfoWidget::InfoWidget(QString nameOfLine, QWidget *parent)
{
    this->setParent(parent);

    _typeLabel = new QLabel(nameOfLine, this);

    _integerValueLabel = new QLabel("integer", this);

    _binaryValueLabel = new QLabel("binary", this);

    _layout = new QHBoxLayout(this);
    _layout->addWidget(_typeLabel);
    _layout->addWidget(_integerValueLabel);
    _layout->addWidget(_binaryValueLabel);

    _layout->setSpacing(10);

}

QLabel *InfoWidget::getIntegerValueLabel() const{
    return _integerValueLabel;
}

QLabel *InfoWidget::getHexValueLabel() const{
    return _integerValueLabel;
}

void InfoWidget::setIntegerValueLabel(QString text){
    _integerValueLabel->setText(text);
}

void InfoWidget::setBinaryValueLabel(QString text){
    _binaryValueLabel->setText(text);
}
