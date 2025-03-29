#include "customview.h"

CustomView::CustomView(QPointF viewSize, QGraphicsScene* scene, QGraphicsView* view)
    :QGraphicsView(view)
{
    this->setScene(scene);
    this->resize(viewSize.x(), viewSize.y());
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
