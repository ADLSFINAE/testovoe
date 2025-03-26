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

    PanelWidget* getPanelWidget()const{return panWgt;};
    CustomTextEdit* getInputWidget()const{return inputWgt;};

private:
    PanelWidget* panWgt{nullptr};
    CustomTextEdit* inputWgt{nullptr};
    QVBoxLayout *mainLayout{nullptr};
};

#endif // GENERALWIDGET_H
