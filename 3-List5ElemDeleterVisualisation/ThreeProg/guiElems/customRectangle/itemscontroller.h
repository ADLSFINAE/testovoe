#ifndef ITEMSCONTROLLER_H
#define ITEMSCONTROLLER_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QVector>
#include <QGraphicsScene>

#include "guiElems/customRectangle/customrectangle.h"
#include "logicElems/list.h"

class ItemsController : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    ItemsController() = default;

    ItemsController(List* head, QGraphicsRectItem* parent = nullptr);

public slots:
    void initAndShowItems(List* head);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    void wheelEvent(QGraphicsSceneWheelEvent *event) override;

signals:
    void signalToDelete5(List* head);

public slots:
    void setListHead(List* head);

private:
    QVector<CustomRectangle*> _vecItems;

    List* _head{nullptr};

};

#endif // ITEMSCONTROLLER_H
