#ifndef GENERALADAPTER_H
#define GENERALADAPTER_H

#include <QObject>
#include <QMap>

#include "logicElems/calcalgorithm.h"

#include "widgetElems/generalwidget.h"
#include "widgetElems/tableElems/customtablewidget.h"

#include "paramsNglobFunctions.h"

class GeneralAdapter : public QObject
{
    Q_OBJECT
public:
    GeneralAdapter();

signals:
    void signalToRedrawTableWidget(QMap<int, int> stats);

    void signalSetBold(bool bold);

    void signalSetCursive(bool cursive);

public slots:
    void slotToCallSetBold();

    void slotToCallSetCursive();

    void slotCreateTableWidget();

    void slotForCallBackToStartAlgorithm();

    void slotSetTextFromLoadTxtFile(QString text);

    void slotSetTextForSaveInTxtFile();

    void slotCleanTextEditFromText();

private:
    GeneralWidget* _genWgt{nullptr};

    CustomTableWidget* _tableWgt{nullptr};

    CalcAlgorithm* _calcAlgo{nullptr};

};

#endif // GENERALADAPTER_H
