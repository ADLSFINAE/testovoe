#include "customblock.h"

CustomBlock::CustomBlock(int x, int y, int number, QGraphicsRectItem *parentItem)
{
    this->setParentItem(parentItem);
    this->setRect(GlobVal::blockRect);
    this->setPos(GlobVal::blockRect.width() * x, GlobVal::blockRect.height() * y);

    textItem = new QGraphicsTextItem(this);
    textItem->setPos(GlobVal::blockRect.width() / 4, GlobVal::blockRect.height() / 4);
    textItem->setPlainText(QString::number(number));

    this->setBrush(Qt::white);
}

void CustomBlock::changeColor(QBrush color)
{
    this->color = color;
    this->setBrush(color);
    this->update(this->rect());
}
