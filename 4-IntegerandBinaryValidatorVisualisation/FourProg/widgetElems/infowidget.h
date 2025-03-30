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

    QLabel* getIntergerValueLabel() const{return integerValueLabel;}

    QLabel* getHexValueLabel() const{return integerValueLabel;}

    void setIntegerValueLabel(QString text){integerValueLabel->setText(text);}

    void setHexValueLabel(QString text){hexValueLabel->setText(text);}

private:
    QLabel* typeLabel{nullptr};

    QLabel* integerValueLabel{nullptr};

    QLabel* hexValueLabel{nullptr};

    QHBoxLayout* layout{nullptr};
};

#endif // INFOWIDGET_H
