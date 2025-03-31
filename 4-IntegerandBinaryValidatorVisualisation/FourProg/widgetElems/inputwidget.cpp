#include "inputwidget.h"

InputWidget::InputWidget(QWidget *parent) : QWidget(parent)
{
    _numberInput = new QLineEdit(this);

    _btnInput = new QPushButton("Ввести число", this);

    /*QIntValidator *validator = new QIntValidator(0, 4294967295, this);
    numberInput->setValidator(validator);
    numberInput->setPlaceholderText("Введите число от 1 до 4 294 967 295");*/

    _layout = new QVBoxLayout(this);

    _layout->addWidget(_numberInput);

    _layout->addWidget(_btnInput);

}

QPushButton *InputWidget::getInputButton() const
{
    return _btnInput;
}

#include <QMessageBox>

quint32 InputWidget::getInputText() const
{
    QString input = _numberInput->text();

    bool ok;

    quint32 value = input.toUInt(&ok);

    if (!ok || input.toULongLong() > 4294967295) {
        QMessageBox::warning(
            const_cast<QWidget*>(qobject_cast<const QWidget*>(this)),
            "Ошибка ввода",
            "Введено недопустимое значение!\n"
            "Пожалуйста, введите число от 0 до 4294967295."
        );
        return 0;
    }

    return value;
}

void InputWidget::slotGetNumber()
{
    emit signalSendNumber(getInputText());

    _numberInput->setText(0);

}
