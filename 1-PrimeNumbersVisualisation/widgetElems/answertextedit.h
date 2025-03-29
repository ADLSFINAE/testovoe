#ifndef ANSWERTEXTEDIT_H
#define ANSWERTEXTEDIT_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>

class AnswerTextEdit : public QWidget
{
    Q_OBJECT
public:
    explicit AnswerTextEdit(QWidget* parent = nullptr) : QWidget(parent)
    {
        // Многострочное поле вывода (только для чтения)
        outputField = new QTextEdit(this);
        outputField->setReadOnly(true);
        outputField->setWordWrapMode(QTextOption::WordWrap);
        outputField->setStyleSheet("QTextEdit { background: #f8f8f8; }");

        // Кнопка очистки
        QPushButton* clearBtn = new QPushButton("Clear Output", this);

        // Компоновка
        QVBoxLayout* layout = new QVBoxLayout(this);
        layout->addWidget(outputField);
        layout->addWidget(clearBtn);

        connect(clearBtn, &QPushButton::clicked, outputField, &QTextEdit::clear);
    }

public slots:
    void appendOutput(const QString& text) {
        outputField->append(text);  // Добавляет текст с новой строки
    }

    void setOutput(const QString& text) {
        outputField->setPlainText(text);  // Заменяет весь текст
    }

private:
    QTextEdit* outputField;
};

#endif // ANSWERTEXTEDIT_H
