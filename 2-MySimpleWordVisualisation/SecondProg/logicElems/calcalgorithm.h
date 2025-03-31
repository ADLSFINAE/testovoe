#ifndef CALCALGORITHM_H
#define CALCALGORITHM_H

#include <QObject>
#include <QCoreApplication>
#include <QString>
#include <QMap>
#include <QRegularExpression>
#include <QDebug>

class CalcAlgorithm : public QObject
{
    Q_OBJECT
public:
    CalcAlgorithm() = default;

    QMap<int, int> countWordLengthsSimple(QString text);

};

#endif // CALCALGORITHM_H
