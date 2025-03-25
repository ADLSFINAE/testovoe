#ifndef CUSTOMVIEW_H
#define CUSTOMVIEW_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
class CustomView : public QGraphicsView
{
    Q_OBJECT
public:
    CustomView(QRectF viewRect, QGraphicsScene* scene, QGraphicsView* view = nullptr);

    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
};

#endif // CUSTOMVIEW_H
