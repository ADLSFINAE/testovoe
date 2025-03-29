#ifndef SIEVEERATOSTHENES_H
#define SIEVEERATOSTHENES_H

#include <QObject>
#include <QVector>

class SieveEratosthenes : public QObject
{
    Q_OBJECT
public:
    SieveEratosthenes() = default;

    QVector<int> algorithm(int n);

private:
    int N;

};


#endif // SIEVEERATOSTHENES_H
