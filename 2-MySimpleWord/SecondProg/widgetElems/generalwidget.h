#ifndef GENERALWIDGET_H
#define GENERALWIDGET_H

#include <QWidget>
#include <QObject>
#include <QApplication>
#include <QScreen>

class GeneralWidget : public QWidget
{
    Q_OBJECT
public:
    GeneralWidget() = default;
    GeneralWidget(QWidget* parent = nullptr);


};

#endif // GENERALWIDGET_H
