#ifndef ANSWERTEXTEDIT_H
#define ANSWERTEXTEDIT_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>

#include "paramsNdefines.h"

class AnswerTextEdit : public QWidget
{
    Q_OBJECT
public:
    AnswerTextEdit() = default;

    AnswerTextEdit(QWidget* parent = nullptr);

public slots:
    void appendOutput(const QString& text);

private:
    QTextEdit* outputField{nullptr};

    QPushButton* clearBtn{nullptr};

    QVBoxLayout* layout{nullptr};
};

#endif // ANSWERTEXTEDIT_H
