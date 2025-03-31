#ifndef GENERALADAPTER_H
#define GENERALADAPTER_H

#include <QObject>
#include <QMessageBox>

#include "guiElems/customscene.h"
#include "guiElems/customview.h"
#include "guiElems/customRectangle/itemscontroller.h"

#include "logicElems/listalgorithm.h"

#include "widgetWithInputNumber/inputwidget.h"

class GeneralAdapter : public QObject
{
    Q_OBJECT
public:
    GeneralAdapter();

public slots:
    void getListHead(List* head);

    void setNumberOfListElems();

private:
    CustomScene* _scene{nullptr};

    CustomView* _view{nullptr};

    ItemsController* _itemsController{nullptr};

    ListAlgorithm* _algo{nullptr};

    List* _head{nullptr};

    InputWidget* _inputWidget{nullptr};
};

#endif // GENERALADAPTER_H
