#include "customview.h"

CustomView::CustomView(QGraphicsScene* scene, QGraphicsView* view)
    :QGraphicsView(view)
{
    this->setScene(scene);
    this->showMaximized();
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
