#include "customscene.h"

CustomScene::CustomScene(QRectF sceneRect, QGraphicsScene *scene)
    :QGraphicsScene(scene)
{
    this->setSceneRect(sceneRect);
}

void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mousePressEvent(event);
}

void CustomScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseReleaseEvent(event);
}

void CustomScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseMoveEvent(event);
}
