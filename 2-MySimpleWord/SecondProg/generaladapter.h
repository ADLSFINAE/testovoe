#ifndef GENERALADAPTER_H
#define GENERALADAPTER_H

#include <QObject>

#include "widgetElems/generalwidget.h"
#include "widgetElems/panelwidget.h"

class GeneralAdapter : public QObject
{
    Q_OBJECT
public:
    GeneralAdapter();

private:
    GeneralWidget* genWgt{nullptr};
    PanelWidget* panWgt{nullptr};
};

#endif // GENERALADAPTER_H
