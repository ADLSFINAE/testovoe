#ifndef INPUTWIDGET_H
#define INPUTWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QIntValidator>
#include <QVBoxLayout>
#include <QMessageBox>

class InputWidget : public QWidget
{
    Q_OBJECT
public:
    InputWidget() = default;

    InputWidget(QWidget* parent);

signals:
    void numberSubmitted(int value);  // Сигнал с введенным числом

private slots:
    void processInput();

private:
    QPushButton* btnInputNumber{nullptr};

    QLineEdit* lineEdit{nullptr};

    QIntValidator* validator{nullptr};

    QVBoxLayout* layout{nullptr};

};

#endif // INPUTWIDGET_H
