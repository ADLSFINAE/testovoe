#include "customblock.h"

CustomBlock::CustomBlock(int x, int y, int number, QGraphicsRectItem *parentItem)
    :_x(x),_y(y),_number(number)
{
    this->setParentItem(parentItem);

    this->setRect(GlobVal::blockRect);

    this->setPos(GlobVal::blockRect.width() * x, GlobVal::blockRect.height() * y);

    this->setBrush(Qt::white);

    _textItem = new QGraphicsTextItem(this);

    _textItem->setPos(GlobVal::blockRect.width() / 4, GlobVal::blockRect.height() / 4);

    _textItem->setPlainText(QString::number(number));

}

void CustomBlock::changeColor(QBrush color)
{
    this->_color = color;

    this->setBrush(color);

    this->update(this->rect());
}

QPointF CustomBlock::getPos() const
{
    return QPointF(_x,_y);
}

int CustomBlock::getNumber() const
{
    return _number;
}

void CustomBlock::setPrimeStatus(bool status)
{
    this->_numberIsPrime = status;
}

bool CustomBlock::getPrimeStatus()
{
    return _numberIsPrime;
}
