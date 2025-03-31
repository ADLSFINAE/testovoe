#include "inputwidget.h"

InputWidget::InputWidget(QWidget *parent) : QWidget(parent)
{
    _numberInput = new QLineEdit(this);

    _btnInput = new QPushButton("Построить односвязный список", this);

    _validator = new QIntValidator(1, 1000, this);

    _numberInput->setValidator(_validator);

    _numberInput->setPlaceholderText("Введите число от 1 до 1000");

    _layout = new QVBoxLayout(this);

    _layout->addWidget(_numberInput);

    _layout->addWidget(_btnInput);

    setFixedSize(300, 100);

}

QPushButton *InputWidget::getInputButton() const
{
    return _btnInput;
}

int InputWidget::getInputText() const
{
    QString input = _numberInput->text();

    return input.toInt();
}

void InputWidget::clearInput()
{
    _numberInput->clear();
}
