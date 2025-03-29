#ifndef CUSTOMBOARD_H
#define CUSTOMBOARD_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QVector>
#include <QDebug>
#include <QTimer>
#include <QEventLoop>

#include "boardElems/customblock.h"
#include "paramsNdefines.h"
#include "guiElems/customscene.h"
#include "logicElems/sieveeratosthenes.h"

class CustomBoard : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    CustomBoard() = default;

    CustomBoard(QRectF rectBoard, int N, QGraphicsRectItem* parent = nullptr);

    QVector<CustomBlock*> getVecBlocks() const;

    void TimerForAnimation(int timeMS){
        QTimer timer;
        QEventLoop loop;
        timer.setSingleShot(true);
        QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
        timer.start(timeMS);
        loop.exec();
        QObject::disconnect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    }

signals:
    void cleanBoard();

    void signalToSendPrimeNumber(const QString& text);

public slots:
    void initVecBlocks(int N);

    void changePosUp();

    void changePosReturn();

    void changeIsTimerOn();

private:
    QVector<CustomBlock*> vecBlocks;

    bool isTimerOn = false;
};

#endif // CUSTOMBOARD_H
