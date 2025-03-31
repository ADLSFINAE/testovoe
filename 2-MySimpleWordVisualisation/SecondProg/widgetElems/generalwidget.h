#ifndef GENERALWIDGET_H
#define GENERALWIDGET_H

#include <QWidget>
#include <QObject>
#include <QApplication>
#include <QScreen>

#include "widgetElems/panelwidget.h"
#include "widgetElems/customtextedit.h"

class GeneralWidget : public QWidget
{
    Q_OBJECT
public:
    GeneralWidget() = default;

    GeneralWidget(QWidget* parent = nullptr);

    PanelWidget* getPanelWidget()const;

    CustomTextEdit* getInputWidget()const;

private:
    PanelWidget* _panWgt{nullptr};

    CustomTextEdit* _inputWgt{nullptr};

    QVBoxLayout* _mainLayout{nullptr};

};

#endif // GENERALWIDGET_H
