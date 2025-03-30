#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QIntValidator>
#include <QString>

class InputWidget : public QWidget
{
    Q_OBJECT
public:
    InputWidget() = default;
    InputWidget(QWidget *parent);

    QPushButton* getInputButton() const;

    quint32 getInputText() const;

signals:
    void signalSendNumber(int number);

public slots:
    void slotGetNumber();

private:
    QLineEdit *numberInput{nullptr};
    QPushButton *btnInput{nullptr};
};

#endif // INPUTWIDGET_H
