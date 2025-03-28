#ifndef TREEVISUALCONTROLLER_H
#define TREEVISUALCONTROLLER_H

#include <QGraphicsRectItem>
#include <QVector>
#include <QSharedPointer>
#include <QMap>
#include <QList>

#include "guiElems/customEllipse/customellipse.h"

class TreeVisualController : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    TreeVisualController() = default;
    TreeVisualController(QGraphicsRectItem* parent = nullptr);

    void buildTree();
    unsigned int findMinK(unsigned int N);

    void rightPlacing();
    void setVecNums(QVector<int> vec){this->vecNums = vec;};

private:
    QList<CustomEllipse*> vecEllipses;
    QVector<int> vecNums = {1,2,3,4,5,NULL,7,8,9,10, NULL};
};

#endif // TREEVISUALCONTROLLER_H
