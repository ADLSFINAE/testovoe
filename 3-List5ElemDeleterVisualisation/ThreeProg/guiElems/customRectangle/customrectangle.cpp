#include "customrectangle.h"

CustomRectangle::CustomRectangle(QRectF rectParams, int number, bool haveArrow, QGraphicsRectItem *parent)
{
    this->_rectParams = rectParams;
    this->_number = number;
    this->_haveArrow = haveArrow;
    this->_pixmapArrow = QPixmap(":/images/1520776820_strelksdsa-1024x454..png");

    this->setParentItem(parent);

    this->setRect(rectParams);

    this->setPos(rectParams.x(), rectParams.y());
    if(_haveArrow){
        _pixmapItem = new QGraphicsPixmapItem(_pixmapArrow, this);
        _pixmapItem->setPixmap(_pixmapArrow.scaled(
                        _rectParams.width(), _rectParams.height(),
                        Qt::KeepAspectRatio,
                        Qt::SmoothTransformation
                    ));
        _pixmapItem->setPos(
                    this->pos().x() + _rectParams.width(), // справа от прямоугольника
                    this->pos().y() + (_rectParams.width()/3) // по центру по вертикали
                    );
    }

    _textItem = new QGraphicsTextItem(QString::number(number), this);
    _textItem->setPos(this->rect().x() + 30, this->rect().y() + 30);
}
