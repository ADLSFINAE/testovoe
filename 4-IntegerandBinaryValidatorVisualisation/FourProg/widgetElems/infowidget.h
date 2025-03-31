#ifndef INFOWIDGET_H
#define INFOWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QIntValidator>
#include <QString>
#include <QLabel>

class InfoWidget : public QWidget
{
    Q_OBJECT
public:
    InfoWidget() = default;

    InfoWidget(QString nameOfLine, QWidget *parent);

    QLabel* getIntegerValueLabel() const;

    QLabel* getHexValueLabel() const;

    void setIntegerValueLabel(QString text);

    void setBinaryValueLabel(QString text);

private:
    QLabel* _typeLabel{nullptr};

    QLabel* _integerValueLabel{nullptr};

    QLabel* _binaryValueLabel{nullptr};

    QHBoxLayout* _layout{nullptr};
};

#endif // INFOWIDGET_H
