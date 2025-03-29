#include "answertextedit.h"

AnswerTextEdit::AnswerTextEdit(QWidget *parent) : QWidget(parent)
{
    this->setGeometry(GlobVal::AnswerTextEditGeometry);

    outputField = new QTextEdit(this);

    outputField->setReadOnly(true);

    outputField->setWordWrapMode(QTextOption::WordWrap);

    outputField->setStyleSheet("QTextEdit { background: #f8f8f8; }");

    clearBtn = new QPushButton("Clear Output", this);

    layout = new QVBoxLayout(this);

    layout->addWidget(outputField);

    layout->addWidget(clearBtn);

    connect(clearBtn, &QPushButton::clicked, outputField, &QTextEdit::clear);
}

void AnswerTextEdit::appendOutput(const QString &text) {
    outputField->append(text);  // Добавляет текст с новой строки
}
