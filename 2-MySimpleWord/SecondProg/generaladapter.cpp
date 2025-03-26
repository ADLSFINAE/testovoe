#include "generaladapter.h"

GeneralAdapter::GeneralAdapter()
{
    genWgt = new GeneralWidget(nullptr);
    genWgt->show();
    QObject::connect(genWgt->getPanelWidget()->getBtnOpenTable(), &QPushButton::clicked,
                     this, &GeneralAdapter::slotCreateTableWidget);

    QObject::connect(genWgt->getInputWgt(), &QTextEdit::textChanged,
                     this, &GeneralAdapter::slotForCallBackToStartAlgorithm);

    calcAlgo = new CalcAlgorithm();

    //customtextedit -> отправит сигнал textChanged() -> который вызовет здесь метод с пустыми параметрами
    //в этом методе вызовем calcAlgo->inputText(text), где текст для него получим из объекта CustomTextEdit::toPlainText();
}

void GeneralAdapter::slotCreateTableWidget()
{

        tableWgt = new CustomTableWidget;
        QObject::connect(this, &GeneralAdapter::signalToRedrawTableWidget,
                         tableWgt, &CustomTableWidget::slotToDoTable);
        tableWgt->show();

}

void GeneralAdapter::slotForCallBackToStartAlgorithm()
{
    calcAlgo->inputText(genWgt->getInputWgt()->toPlainText());
    emit signalToRedrawTableWidget(calcAlgo->countWordLengthsSimple(genWgt->getInputWgt()->toPlainText()));
    //дальше тут добавляем emit signalToRedrawTableWidget(QVector<QVector<int, int>>)
    //этот сигнал связываем с tablewidget - заполняем таблицу заново
}
