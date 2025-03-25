#ifndef CUSTOMBLOCK_H
#define CUSTOMBLOCK_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QObject>
#include <QPen>
#include <QBrush>
#include <QGraphicsTextItem>

#include "paramsNdefines.h"

class CustomBlock : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    CustomBlock() = default;
    CustomBlock(int x, int y, int number, QGraphicsRectItem* parentItem);

    void changeColor(QBrush brush);

private:
    int x, y;
    QBrush color;
    int number;
    QGraphicsTextItem* textItem{nullptr};
};

#endif // CUSTOMBLOCK_H
