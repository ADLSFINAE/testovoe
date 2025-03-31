#ifndef GENERALWIDGET_H
#define GENERALWIDGET_H

#include <QWidget>
#include <QHBoxLayout>

#include "widgetElems/controllerwidget.h"
#include "widgetElems/inputwidget.h"

#include "paramsNdefines.h"

class GeneralWidget : public QWidget
{
    Q_OBJECT
public:
    GeneralWidget() = default;

    GeneralWidget(QWidget* parent = nullptr);

    ControllerWidget* getControllerWidget() const;

    InputWidget* getInputWidget() const;

private:
    QHBoxLayout* _layout{nullptr};

    ControllerWidget* _controllerWidget{nullptr};

    InputWidget* _inputWidget{nullptr};

};

#endif // GENERALWIDGET_H
