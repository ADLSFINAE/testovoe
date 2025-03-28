#ifndef CUSTOMELLIPSE_H
#define CUSTOMELLIPSE_H

#include <QGraphicsEllipseItem>
#include <QBrush>
#include <QString>
#include <QGraphicsSceneMouseEvent>

class CustomEllipse : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    CustomEllipse() = default;
    CustomEllipse(QPointF pos, int number, QGraphicsItem* parent);

    QPointF getPos() const{return posix;};
    int getNumber() const{return number;};
    QBrush getBrush() const{return brush;};
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
private:
    QGraphicsTextItem* textItem;

    QPointF posix;
    QBrush brush;
    int number;
};

#endif // CUSTOMELLIPSE_H
