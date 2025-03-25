#ifndef PARAMSNDEFINES_H
#define PARAMSNDEFINES_H

#include <QRectF>
#include <QPointF>

namespace GlobVal{

inline QRectF sceneRect = QRectF(0, 0, 800, 800);
inline QRectF viewRect = QRectF(0, 0, 810, 810);

inline QRectF blockRect = QRectF(0, 0, 40, 40);

inline QRectF boardSolver = QRectF(0, 0, 400, 800);

inline QRect generalWidgetGeometry = QRect(401, 0, 400, 100);

inline QRect generalTextEditGeometry = QRect(401, 0, 400, 100);
};

#endif // PARAMSNDEFINES_H
