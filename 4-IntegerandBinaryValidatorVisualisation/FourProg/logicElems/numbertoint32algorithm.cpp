#include "numbertoint32algorithm.h"

NumberToInt32Algorithm::NumberToInt32Algorithm()
{
    QObject::connect(this, &NumberToInt32Algorithm::signalGetAns,
                     this, &NumberToInt32Algorithm::slotGetAns);
}

QPair<quint32, quint32> NumberToInt32Algorithm::algorithm(quint32 number)
{
    this->number = number;
    quint32 count = 0;

    for (quint32 i = 0; i < 32; ++i) {
        if (number & (1 << i)){
            count++;
        }
    }

    // тута блять младшие count битов установлены в 1, остальные в 0
    quint32 min_num = (1u << count) - 1;

    // тама блять старшие count битов установлены в 1, отстальные в 0
    quint32 max_num = (0xFFFFFFFFu << (32 - count)) & 0xFFFFFFFFu;

    return {min_num, max_num};
}

void NumberToInt32Algorithm::slotGetAns()
{
    _ans = algorithm(number);
}



