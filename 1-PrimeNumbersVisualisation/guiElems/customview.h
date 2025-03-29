#ifndef CUSTOMVIEW_H
#define CUSTOMVIEW_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
class CustomView : public QGraphicsView
{
    Q_OBJECT
public:
    CustomView() = default;

    CustomView(QPointF viewSize, QGraphicsScene* scene, QGraphicsView* view = nullptr);

protected:
    void mousePressEvent(QMouseEvent* event) override;

    void mouseReleaseEvent(QMouseEvent* event) override;

    void mouseMoveEvent(QMouseEvent* event) override;

};

#endif // CUSTOMVIEW_H
