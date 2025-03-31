#ifndef NUMBERTOINT32ALGORITHM_H
#define NUMBERTOINT32ALGORITHM_H

#include <QObject>
#include <QPair>

class NumberToInt32Algorithm : public QObject
{
    Q_OBJECT
public:
    NumberToInt32Algorithm();

    QPair<quint32, quint32> algorithm(quint32 number);

    QPair<quint32, quint32> getAns() const{return _ans;}

signals:
    void signalGetAns();

private slots:
    void slotGetAns();

private:
    QPair<quint32, quint32> _ans;

    quint32 _number;

};

#endif // NUMBERTOINT32ALGORITHM_H
