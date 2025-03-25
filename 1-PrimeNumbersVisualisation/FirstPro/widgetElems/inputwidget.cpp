#include "inputwidget.h"


InputWidget::InputWidget(QWidget *parent)
{
    this->setParent(parent);
    this->show();
    // Создаем элементы интерфейса
    lineEdit = new QLineEdit(this);
    btnInputNumber = new QPushButton("Submit", this);

    // Настраиваем валидатор для ввода чисел от 0 до maxN
    QIntValidator* validator = new QIntValidator(0, 201, this);
    lineEdit->setValidator(validator);

    // Настраиваем layout
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(lineEdit);
    layout->addWidget(btnInputNumber);

    // Подключаем сигнал кнопки
    connect(btnInputNumber, &QPushButton::clicked, this, &InputWidget::processInput);
}

void InputWidget::processInput()
{
    if (lineEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter a number");
        return;
    }

    bool ok;
    int value = lineEdit->text().toInt(&ok);

    if (ok && value >= 0 && value <= 201) {
        emit numberSubmitted(value);  // Отправляем сигнал
        lineEdit->clear();           // Очищаем поле
    } else {
        QMessageBox::warning(this, "Error",
            QString("Please enter a number between 0 and %1").arg(201));
    }
}
