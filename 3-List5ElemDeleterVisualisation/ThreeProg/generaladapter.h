#ifndef GENERALADAPTER_H
#define GENERALADAPTER_H

#include <QObject>

#include "guiElems/customscene.h"
#include "guiElems/customview.h"
#include "guiElems/customRectangle/itemscontroller.h"

class GeneralAdapter : public QObject
{
    Q_OBJECT
public:
    GeneralAdapter();

private:
    CustomScene* scene{nullptr};
    CustomView* view{nullptr};

    ItemsController* itemsController{nullptr};
};

#endif // GENERALADAPTER_H
