#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QIntValidator>
#include <QString>

class InputWidget : public QWidget
{
    Q_OBJECT

public:
    InputWidget() = default;

    InputWidget(QWidget *parent = nullptr);

    QPushButton* getInputButton() const;

    int getInputText() const;

private slots:
    void clearInput();

private:
    QLineEdit* _numberInput{nullptr};

    QPushButton* _btnInput{nullptr};

    QIntValidator* _validator{nullptr};

    QVBoxLayout *_layout{nullptr};

};

#endif // INPUTWIDGET_H
