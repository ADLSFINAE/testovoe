#ifndef ITEMSCONTROLLER_H
#define ITEMSCONTROLLER_H

#include <QGraphicsRectItem>
#include <QVector>

#include "guiElems/customRectangle/customrectangle.h"

class ItemsController : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    ItemsController() = default;
    ItemsController(int N, QGraphicsRectItem* parent = nullptr);

    void initAndShowItems(int N);
private:
    QVector<CustomRectangle*> vecItems;
};

#endif // ITEMSCONTROLLER_H
