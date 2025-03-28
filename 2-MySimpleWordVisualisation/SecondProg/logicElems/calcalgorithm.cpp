#include "calcalgorithm.h"

QMap<int, int> CalcAlgorithm::countWordLengthsSimple(QString text)
{
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
