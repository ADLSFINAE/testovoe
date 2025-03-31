#include "answertextedit.h"

AnswerTextEdit::AnswerTextEdit(QWidget *parent) : QWidget(parent)
{
    this->setGeometry(GlobVal::AnswerTextEditGeometry);

    _outputField = new QTextEdit(this);

    _outputField->setReadOnly(true);

    _outputField->setWordWrapMode(QTextOption::WordWrap);

    _outputField->setStyleSheet("QTextEdit { background: #f8f8f8; }");

    _clearBtn = new QPushButton("Clear Output", this);

    _layout = new QVBoxLayout(this);

    _layout->addWidget(_outputField);

    _layout->addWidget(_clearBtn);

    //коннект для очистки поля ввода, после нажатия submit'а
    QObject::connect(_clearBtn, &QPushButton::clicked, _outputField, &QTextEdit::clear);
}

void AnswerTextEdit::appendOutput(const QString &text) {
    _outputField->append(text);
}
