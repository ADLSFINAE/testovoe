#include "generaladapter.h"

GeneralAdapter::GeneralAdapter()
{
    genWgt = new GeneralWidget(nullptr);
    genWgt->show();
    //создание таблицы
    QObject::connect(genWgt->getPanelWidget()->getBtnOpenTable(), &QPushButton::clicked,
                     this, &GeneralAdapter::slotCreateTableWidget);
    //запуск алгоритма для таблицы
    QObject::connect(genWgt->getInputWgt(), &QTextEdit::textChanged,
                     this, &GeneralAdapter::slotForCallBackToStartAlgorithm);

    //кнопки для изменения стиля
    QObject::connect(genWgt->getPanelWidget()->getBtnSetFattFormat(), &QPushButton::clicked,
                     this, &GeneralAdapter::slotToCallSetBold);

    QObject::connect(this, &GeneralAdapter::signalSetBold,
                     genWgt->getInputWgt(), &CustomTextEdit::slotSetBoldText);

    QObject::connect(genWgt->getPanelWidget()->getBtnSetCursiveFormat(), &QPushButton::clicked,
                     this, &GeneralAdapter::slotToCallSetCursive);

    QObject::connect(this, &GeneralAdapter::signalSetCursive,
                     genWgt->getInputWgt(), &CustomTextEdit::slotSetCursiveText);

    calcAlgo = new CalcAlgorithm();

    //customtextedit -> отправит сигнал textChanged() -> который вызовет здесь метод с пустыми параметрами
    //в этом методе вызовем calcAlgo->inputText(text), где текст для него получим из объекта CustomTextEdit::toPlainText();
}

void GeneralAdapter::slotToCallSetBold()
{
    emit signalSetBold(genWgt->getPanelWidget()->getBtnSetFattFormat()->getIsActive());
}

void GeneralAdapter::slotToCallSetCursive()
{
    emit signalSetCursive(genWgt->getPanelWidget()->getBtnSetCursiveFormat()->getIsActive());
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
    //calcAlgo->inputText(genWgt->getInputWgt()->toPlainText());
    emit signalToRedrawTableWidget(calcAlgo->countWordLengthsSimple(genWgt->getInputWgt()->toPlainText()));
    //дальше тут добавляем emit signalToRedrawTableWidget(QVector<QVector<int, int>>)
    //этот сигнал связываем с tablewidget - заполняем таблицу заново
}
