#include "customview.h"

CustomView::CustomView(QRectF viewRect, QGraphicsScene* scene, QGraphicsView* view)
    :QGraphicsView(view)
{
    this->setScene(scene);
    this->setFixedSize(viewRect.width(), viewRect.height());
}

void CustomView::mousePressEvent(QMouseEvent *event)
{
    QGraphicsView::mousePressEvent(event);
}

void CustomView::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);
}

void CustomView::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);
}
