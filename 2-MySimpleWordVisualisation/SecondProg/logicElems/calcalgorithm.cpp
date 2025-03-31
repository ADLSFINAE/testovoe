#include "calcalgorithm.h"

QMap<int, int> CalcAlgorithm::countWordLengthsSimple(QString text)
{
    QMap<int, int> lengthCounts;

    // Взял QRegExpression для поиска слов (учитывает апострофы и дефисы - тут только английский язык)
    // Русский он считает wchar'ом - у меня не получилось с ними сработаться
    // может у вас будет работать, но у меня даже в обычной консоли русский не работает - пробовал setlocale(LC_ALL, "ru")
    QRegularExpression wordRegex("\\b[\\w'-]+\\b");
    QRegularExpressionMatchIterator it = wordRegex.globalMatch(text);

    while (it.hasNext()) {
        QString word = it.next().captured();
        int length = word.length();
        lengthCounts[length]++;
    }

    return lengthCounts;
}
