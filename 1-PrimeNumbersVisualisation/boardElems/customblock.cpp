#include "customblock.h"

CustomBlock::CustomBlock(int x, int y, int number, QGraphicsRectItem *parentItem)
    :x(x),y(y),number(number)
{
    this->setParentItem(parentItem);

    this->setRect(GlobVal::blockRect);

    this->setPos(GlobVal::blockRect.width() * x, GlobVal::blockRect.height() * y);

    this->setBrush(Qt::white);

    textItem = new QGraphicsTextItem(this);

    textItem->setPos(GlobVal::blockRect.width() / 4, GlobVal::blockRect.height() / 4);

    textItem->setPlainText(QString::number(number));

}

void CustomBlock::changeColor(QBrush color)
{
    this->color = color;

    this->setBrush(color);

    this->update(this->rect());
}

QPointF CustomBlock::getPos() const
{
    return QPointF(x,y);
}

int CustomBlock::getNumber() const
{
    return number;
}

void CustomBlock::setPrimeStatus(bool status)
{
    this->numberIsPrime = status;
}

bool CustomBlock::getPrimeStatus()
{
    return numberIsPrime;
}
