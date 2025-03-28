#include "customview.h"
#include <QScrollBar>
#include <QApplication>

CustomView::CustomView(QGraphicsScene* scene, QWidget* parent)
    : QGraphicsView(scene, parent),
      m_isPanning(false),
      m_panStartPos(0, 0),
      m_zoomFactor(1.15) // Стандартный коэффициент масштабирования
{
    // Настройки отображения
    setRenderHint(QPainter::Antialiasing);
    setRenderHint(QPainter::SmoothPixmapTransform);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setResizeAnchor(QGraphicsView::AnchorUnderMouse);
    setInteractive(true);
}

void CustomView::mousePressEvent(QMouseEvent* event)
{
    /*if (event->button() == Qt::LeftButton) {
        // При нажатии левой кнопки мыши - включаем режим перемещения
        m_isPanning = true;
        m_panStartPos = event->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        return;
    }
    else if (event->button() == Qt::MiddleButton) {
        // При нажатии средней кнопки мыши - тоже включаем режим перемещения
        m_isPanning = true;
        m_panStartPos = event->pos();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        return;
    }*/
    QGraphicsView::mousePressEvent(event);
}

void CustomView::mouseReleaseEvent(QMouseEvent* event)
{
    /*if (event->button() == Qt::LeftButton || event->button() == Qt::MiddleButton) {
        // При отпускании левой или средней кнопки - выключаем режим перемещения
        m_isPanning = false;
        setCursor(Qt::ArrowCursor);
        event->accept();
        return;
    }*/
    QGraphicsView::mouseReleaseEvent(event);
}

void CustomView::mouseMoveEvent(QMouseEvent* event)
{
    /*if (m_isPanning) {
        // Перемещение сцены при зажатой левой или средней кнопке мыши
        QScrollBar* hBar = horizontalScrollBar();
        QScrollBar* vBar = verticalScrollBar();
        QPoint delta = event->pos() - m_panStartPos;
        hBar->setValue(hBar->value() - delta.x());
        vBar->setValue(vBar->value() - delta.y());
        m_panStartPos = event->pos();
        event->accept();
        return;
    }*/
    QGraphicsView::mouseMoveEvent(event);
}

void CustomView::wheelEvent(QWheelEvent* event)
{
    // Масштабирование при прокрутке колеса мыши
    if (QApplication::keyboardModifiers() == Qt::ControlModifier) {
        // При зажатом Ctrl масштабируем более плавно
        double angle = event->angleDelta().y();
        double factor = qPow(1.0015, angle);
        zoom(factor);
    } else {
        // Обычное масштабирование
        double angle = event->angleDelta().y();
        if (angle > 0) {
            zoom(m_zoomFactor);
        } else if (angle < 0) {
            zoom(1.0 / m_zoomFactor);
        }
    }
    event->accept();
}

void CustomView::zoom(double factor)
{
    // Применяем масштабирование с ограничениями
    const double currentScale = transform().m11();
    const double minScale = 0.1;    // Минимальный масштаб
    const double maxScale = 10.0;   // Максимальный масштаб

    if ((factor < 1 && currentScale > minScale) ||
        (factor > 1 && currentScale < maxScale)) {
        scale(factor, factor);
    }
}
