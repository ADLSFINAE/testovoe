#ifndef CUSTOMBOARD_H
#define CUSTOMBOARD_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QVector>
#include <QDebug>

#include "boardElems/customblock.h"
#include "paramsNdefines.h"

class CustomBoard : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    CustomBoard() = default;
    CustomBoard(QRectF rectBoard, int N, QGraphicsRectItem* parent = nullptr);

    QVector<CustomBlock*> getVecBlocks() const{
        return vecBlocks;
    }
signals:
    void cleanBoard();
    void signalToSendPrimeNumber(const QString& text);
public slots:
    void initVecBlocks(int N);
    void changePosUp();
    void changePosReturn();
private:
    QVector<CustomBlock*> vecBlocks;
};

#endif // CUSTOMBOARD_H
