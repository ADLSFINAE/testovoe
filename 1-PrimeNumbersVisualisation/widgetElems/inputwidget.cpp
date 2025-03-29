#include "inputwidget.h"

InputWidget::InputWidget(QWidget *parent)
{
    this->setParent(parent);
    this->show();

    lineEdit = new QLineEdit(this);

    btnInputNumber = new QPushButton("Submit", this);

    validator = new QIntValidator(2, 10000, this);

    lineEdit->setValidator(validator);

    QVBoxLayout* layout = new QVBoxLayout(this);

    layout->addWidget(lineEdit);

    layout->addWidget(btnInputNumber);

    QObject::connect(btnInputNumber, &QPushButton::clicked, this, &InputWidget::processInput);
}

void InputWidget::processInput()
{
    if (lineEdit->text().isEmpty()) {
        QMessageBox::warning(nullptr, "Error", "Please enter a number");
        return;
    }

    bool ok;
    int value = lineEdit->text().toInt(&ok);

    if (ok && value >= 2 && value <= 10000) {
        emit numberSubmitted(value);
        lineEdit->clear();
    } else {
        QMessageBox::warning(nullptr, "Error",
                             QString("Please enter a number between 2 and %1").arg(10000));
    }
}
