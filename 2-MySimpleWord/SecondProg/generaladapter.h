#ifndef GENERALADAPTER_H
#define GENERALADAPTER_H

#include <QObject>

#include "widgetElems/generalwidget.h"

class GeneralAdapter : public QObject
{
    Q_OBJECT
public:
    GeneralAdapter();

private:
    GeneralWidget* genWgt{nullptr};
};

#endif // GENERALADAPTER_H
