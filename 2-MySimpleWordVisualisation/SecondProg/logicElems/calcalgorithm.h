#ifndef CALCALGORITHM_H
#define CALCALGORITHM_H

#include <QObject>
#include <QCoreApplication>
#include <QString>
#include <QMap>
#include <QRegularExpression>
#include <QDebug>

class CalcAlgorithm
{
    //Q_OBJECT
public:
    CalcAlgorithm(){};

    QMap<int, int> countWordLengthsSimple(QString text);

private:
    QString sampleText;
};

#endif // CALCALGORITHM_H
