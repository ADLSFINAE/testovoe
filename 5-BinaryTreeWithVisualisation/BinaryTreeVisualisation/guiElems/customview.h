#ifndef CUSTOMVIEW_H
#define CUSTOMVIEW_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
class CustomView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit CustomView(QGraphicsScene* scene, QWidget* parent = nullptr);

    // Обработчики событий мыши
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;

private:
    bool m_isPanning;       // Флаг перемещения сцены
    QPoint m_panStartPos;   // Начальная позиция при перемещении
    double m_zoomFactor;    // Фактор масштабирования

    void zoom(double factor); // Функция масштабирования
};

#endif // CUSTOMVIEW_H

