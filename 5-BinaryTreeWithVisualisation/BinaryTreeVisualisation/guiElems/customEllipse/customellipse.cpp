#include "customellipse.h"

CustomEllipse::CustomEllipse(QPointF pos, int number, QGraphicsItem *parent)
{
    this->setParentItem(parent);

    this->posix = pos;
    this->brush = QBrush(Qt::white);
    this->number = number;

    this->setRect(QRectF(0, 0, 40, 40));
    this->setPos(pos);

    textItem = new QGraphicsTextItem(QString::number(number), this);
    textItem->setPos(10, 10);

}

void CustomEllipse::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    this->setBrush(QBrush(Qt::green));
}
