#ifndef LISTALGORITHM_H
#define LISTALGORITHM_H

#include <QObject>
#include <QVector>

#include "logicElems/list.h"

class ListAlgorithm : public QObject
{
    Q_OBJECT
public:
    ListAlgorithm();

    void initList(int N);

    void cleanList();

    List* getHead() const{return head;}
signals:
    void signalToRedrawItems(List* head);
public slots:
    void deleteEveryFifth(List* head);
private:
    List* head;
};

#endif // LISTALGORITHM_H
