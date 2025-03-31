#ifndef CUSTOMRECTANGLE_H
#define CUSTOMRECTANGLE_H

#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>

class CustomRectangle : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    CustomRectangle() = default;

    CustomRectangle(QRectF rectParams, int number, bool haveArrow, QGraphicsRectItem* parent);

    void setHaveArrow(bool haveArrow){this->_haveArrow = haveArrow;}

    bool getHaveArrow() const{return _haveArrow;}

private:
    QGraphicsTextItem* _textItem{nullptr};

    QRectF _rectParams;

    int _number;

    QGraphicsPixmapItem* _pixmapItem{nullptr};

    QPixmap _pixmapArrow;

    bool _haveArrow;

};

#endif // CUSTOMRECTANGLE_H
