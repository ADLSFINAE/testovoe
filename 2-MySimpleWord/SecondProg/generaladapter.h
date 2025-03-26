#ifndef GENERALADAPTER_H
#define GENERALADAPTER_H

#include <QObject>
#include <QMap>

#include "logicElems/calcalgorithm.h"

#include "widgetElems/generalwidget.h"
#include "widgetElems/tableElems/customtablewidget.h"

class GeneralAdapter : public QObject
{
    Q_OBJECT
public:
    GeneralAdapter();
signals:
    void signalToRedrawTableWidget(QMap<int, int> stats);
public slots:
    void slotCreateTableWidget();
    void slotForCallBackToStartAlgorithm();
private:
    GeneralWidget* genWgt{nullptr};
    CustomTableWidget* tableWgt{nullptr};
    CalcAlgorithm* calcAlgo{nullptr};
};

#endif // GENERALADAPTER_H
