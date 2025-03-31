#include "generaladapter.h"

GeneralAdapter::GeneralAdapter()
{
    _generalWidget = new GeneralWidget(nullptr);
    _generalWidget->show();

    _numAlgos = new NumberToInt32Algorithm();

    QObject::connect(_generalWidget->getInputWidget()->getInputButton(), &QPushButton::clicked,
                     _generalWidget->getInputWidget(), &InputWidget::slotGetNumber);

    QObject::connect(_generalWidget->getInputWidget(), &InputWidget::signalSendNumber,
                     this, &GeneralAdapter::slotGetNumberFromInput);

    QObject::connect(this, &GeneralAdapter::signalLabel1,
                     _generalWidget, &GeneralWidget::slotSetNumberLabelValues);

    QObject::connect(this, &GeneralAdapter::signalLabel2,
                     _generalWidget, &GeneralWidget::slotSetNumberLabelMin);

    QObject::connect(this, &GeneralAdapter::signalLabel3,
                     _generalWidget, &GeneralWidget::slotSetNumberLabelMax);
}

void GeneralAdapter::slotGetNumberFromInput(quint32 numberFromInput)
{
    this->_numberFromInput = numberFromInput;

    QPair<quint32, quint32> minAndMaxVals = _numAlgos->algorithm(_numberFromInput);

    emit signalLabel1(_numberFromInput);
    emit signalLabel2(minAndMaxVals.first);
    emit signalLabel3(minAndMaxVals.second);
}
