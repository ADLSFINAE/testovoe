#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class CustomScene : public QGraphicsScene
{
    Q_OBJECT
public:
    CustomScene(QRectF sceneRect,QGraphicsScene* parent = nullptr);
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
};

#endif // CUSTOMSCENE_H
