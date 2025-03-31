#include "inputwidget.h"

InputWidget::InputWidget(QWidget *parent)
{
    this->setParent(parent);
    this->show();

    _lineEdit = new QLineEdit(this);

    _btnInputNumber = new QPushButton("Submit", this);

    _validator = new QIntValidator(2, 10000, this);

    _lineEdit->setValidator(_validator);

    _layout = new QVBoxLayout(this);

    _layout->addWidget(_lineEdit);

    _layout->addWidget(_btnInputNumber);

    //коннект для вызова QMessageBox, если введенное значение не попало в допустимый интервал
    QObject::connect(_btnInputNumber, &QPushButton::clicked, this, &InputWidget::processInput);
}

void InputWidget::processInput()
{
    if(_lineEdit->text().isEmpty()){
        QMessageBox::warning(nullptr, "Error", "Please enter a number");
        return;
    }

    bool ok;
    int value = _lineEdit->text().toInt(&ok);

    if(ok &&
            value >= 2 &&
            value <= 10000){
        emit numberSubmitted(value);
        _lineEdit->clear();
    }

    else{
        QMessageBox::warning(nullptr, "Error",
                             QString("Please enter a number between 2 and %1").arg(10000));
    }
}
