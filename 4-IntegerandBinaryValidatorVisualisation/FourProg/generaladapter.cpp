#include "generaladapter.h"

GeneralAdapter::GeneralAdapter()
{
    generalWidget = new GeneralWidget(nullptr);
    generalWidget->show();

    numAlgos = new NumberToInt32Algorithm();

    QObject::connect(generalWidget->getInputWidget()->getInputButton(), &QPushButton::clicked,
                     generalWidget->getInputWidget(), &InputWidget::slotGetNumber);

    QObject::connect(generalWidget->getInputWidget(), &InputWidget::signalSendNumber,
                     this, &GeneralAdapter::slotGetNumberFromInput);

    QObject::connect(this, &GeneralAdapter::signalLabel1,
                     generalWidget, &GeneralWidget::slotSetNumberLabelValues);

    QObject::connect(this, &GeneralAdapter::signalLabel2,
                     generalWidget, &GeneralWidget::slotSetNumberLabelMin);

    QObject::connect(this, &GeneralAdapter::signalLabel3,
                     generalWidget, &GeneralWidget::slotSetNumberLabelMax);
}

void GeneralAdapter::slotGetNumberFromInput(quint32 numberFromInput)
{
    this->_numberFromInput = numberFromInput;

    QPair<quint32, quint32> minAndMaxVals = numAlgos->algorithm(_numberFromInput);

    emit signalLabel1(_numberFromInput);
    emit signalLabel2(minAndMaxVals.first);
    emit signalLabel3(minAndMaxVals.second);
}

void GeneralAdapter::slotSetValues()
{

}
