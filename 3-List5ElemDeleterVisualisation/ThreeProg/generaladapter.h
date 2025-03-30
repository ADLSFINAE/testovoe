#ifndef GENERALADAPTER_H
#define GENERALADAPTER_H

#include <QObject>

#include "guiElems/customscene.h"
#include "guiElems/customview.h"
#include "guiElems/customRectangle/itemscontroller.h"

#include "logicElems/listalgorithm.h"

class GeneralAdapter : public QObject
{
    Q_OBJECT
public:
    GeneralAdapter();

public slots:
    void getListHead(List* head);

private:
    CustomScene* scene{nullptr};
    CustomView* view{nullptr};

    ItemsController* itemsController{nullptr};

    ListAlgorithm* algo{nullptr};

    List* head{nullptr};
};

#endif // GENERALADAPTER_H
