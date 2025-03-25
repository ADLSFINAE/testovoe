#ifndef GENERALWIDGET_H
#define GENERALWIDGET_H

#include <QWidget>
#include <QHBoxLayout>

#include "widgetElems/controllerwidget.h"
#include "widgetElems/inputwidget.h"

class GeneralWidget : public QWidget
{
    Q_OBJECT
public:
    GeneralWidget() = default;
    GeneralWidget(QWidget* parent = nullptr);

    ControllerWidget* getControllerWidget() const{return controllerWidget;};
    InputWidget* getInputWidget() const{return inputWidget;};
private:
    QHBoxLayout* layout{nullptr};

    ControllerWidget* controllerWidget{nullptr};
    InputWidget* inputWidget{nullptr};
};

#endif // GENERALWIDGET_H
