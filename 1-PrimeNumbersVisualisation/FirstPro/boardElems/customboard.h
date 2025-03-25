#ifndef CUSTOMBOARD_H
#define CUSTOMBOARD_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QVector>

#include "boardElems/customblock.h"
#include "paramsNdefines.h"

class CustomBoard : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    CustomBoard() = default;
    CustomBoard(QRectF rectBoard, int N, QGraphicsRectItem* parent = nullptr);

    void initVecBlocks(int N);

private:
    QVector<CustomBlock*> vecBlocks;
};

#endif // CUSTOMBOARD_H
