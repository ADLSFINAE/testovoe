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

    QMap<int, int> countWordLengthsSimple(QString text) {
        QMap<int, int> lengthCounts;

        // Регулярное выражение для поиска слов (учитывает апострофы и дефисы)
        QRegularExpression wordRegex("\\b[\\w'-]+\\b");
        QRegularExpressionMatchIterator it = wordRegex.globalMatch(text);

        while (it.hasNext()) {
            QString word = it.next().captured();
            int length = word.length();
            lengthCounts[length]++;
        }

        return lengthCounts;
    }

    void printWordLengthStats(QMap<int, int> stats) {
        qDebug() << "\nСтатистика длины слов:";
        qDebug() << "Длина | Количество";
        qDebug() << "------+-----------";

        int totalWords = 0;
        for (auto it = stats.begin(); it != stats.end(); ++it) {
            qDebug() << QString("%1     | %2").arg(it.key(), 5).arg(it.value());
            totalWords += it.value();
        }

        qDebug() << "\nВсего слов:" << totalWords;
    }

    void use(){
        QMap<int, int> simpleCounts = countWordLengthsSimple(sampleText);
        printWordLengthStats(simpleCounts);
    }

    void inputText(QString string){
        sampleText = string;
        printWordLengthStats(countWordLengthsSimple(sampleText));
    }

private:
    QString sampleText;
};

#endif // CALCALGORITHM_H
