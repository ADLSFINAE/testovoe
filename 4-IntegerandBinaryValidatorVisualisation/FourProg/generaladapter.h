#ifndef GENERALADAPTER_H
#define GENERALADAPTER_H

#include <QObject>

#include "widgetElems/generalwidget.h"
#include "logicElems/numbertoint32algorithm.h"

class GeneralAdapter : public QObject
{
    Q_OBJECT
public:
    GeneralAdapter();

signals:
    void signalLabel1(quint32 numberFromInput);

    void signalLabel2(quint32 numberFromInput);

    void signalLabel3(quint32 numberFromInput);

private slots:
    void slotGetNumberFromInput(quint32 numberFromInput);

private:
    GeneralWidget* _generalWidget{nullptr};

    NumberToInt32Algorithm* _numAlgos{nullptr};

    int _numberFromInput;
};

#endif // GENERALADAPTER_H
