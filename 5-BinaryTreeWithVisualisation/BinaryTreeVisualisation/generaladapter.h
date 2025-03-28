#ifndef GENERALADAPTER_H
#define GENERALADAPTER_H

#include <QObject>

#include "guiElems/customEllipse/customellipse.h"
#include "guiElems/TreeVisualisation/treevisualcontroller.h"

#include "guiElems/customscene.h"
#include "guiElems/customview.h"

#include "logicElems/treealgorithm.h"

#include <QVector>
#include <QPair>
#include <QDebug>
#include <cmath>

using namespace Qt;

class GeneralAdapter : public QObject
{
    Q_OBJECT
public:
    GeneralAdapter();
    QVector<int> getVec(const QVector<QPair<int, int>>& vec);
    QVector<int> shitParser(QVector<int> vec);
    unsigned int findMinK(unsigned int N);
private:
    CustomScene* scene{nullptr};
    CustomView* view{nullptr};

    TreeAlgorithm* algo{nullptr};

    TreeVisualController* visualController{nullptr};
};

#endif // GENERALADAPTER_H
