#include "generaladapter.h"

GeneralAdapter::GeneralAdapter()
{

    genWgt = new GeneralWidget(nullptr);
    genWgt->show();

    //создание таблицы
    QObject::connect(PANEL_WIDGET(genWgt)->getBtnOpenTable(), &QPushButton::clicked,
                     this, &GeneralAdapter::slotCreateTableWidget);
    //запуск алгоритма для таблицы
    QObject::connect(TEXTEDIT_WIDGET(genWgt), &QTextEdit::textChanged,
                     this, &GeneralAdapter::slotForCallBackToStartAlgorithm);

    //кнопки для изменения стиля
    QObject::connect(PANEL_WIDGET(genWgt)->getBtnSetFattFormat(), &QPushButton::clicked,
                     this, &GeneralAdapter::slotToCallSetBold);

    QObject::connect(this, &GeneralAdapter::signalSetBold,
                     TEXTEDIT_WIDGET(genWgt), &CustomTextEdit::slotSetBoldText);

    QObject::connect(PANEL_WIDGET(genWgt)->getBtnSetCursiveFormat(), &QPushButton::clicked,
                     this, &GeneralAdapter::slotToCallSetCursive);

    QObject::connect(this, &GeneralAdapter::signalSetCursive,
                     TEXTEDIT_WIDGET(genWgt), &CustomTextEdit::slotSetCursiveText);

    //коннект для загрузки файла
    QObject::connect(PANEL_WIDGET(genWgt), &PanelWidget::signalTextLoadToTextEdit,
                     this, &GeneralAdapter::slotSetTextFromLoadTxtFile);

    //коннект для сохранения файла
    QObject::connect(PANEL_WIDGET(genWgt), &PanelWidget::signalToGetTextFromTextEdit,
                     this, &GeneralAdapter::slotSetTextForSaveInTxtFile);

    //коннект для очистки бляяяяяяяяя
    QObject::connect(PANEL_WIDGET(genWgt), &PanelWidget::signalCleanTextEdit,
                     this, &GeneralAdapter::slotCleanTextEditFromText);

    calcAlgo = new CalcAlgorithm();

    //customtextedit -> отправит сигнал textChanged() -> который вызовет здесь метод с пустыми параметрами
    //в этом методе вызовем calcAlgo->inputText(text), где текст для него получим из объекта CustomTextEdit::toPlainText();
}

void GeneralAdapter::slotToCallSetBold()
{
    emit signalSetBold(PANEL_WIDGET(genWgt)->getBtnSetFattFormat()->getIsActive());
}

void GeneralAdapter::slotToCallSetCursive()
{
    emit signalSetCursive(PANEL_WIDGET(genWgt)->getBtnSetCursiveFormat()->getIsActive());
}

void GeneralAdapter::slotCreateTableWidget()
{
    tableWgt = new CustomTableWidget;
    QObject::connect(this, &GeneralAdapter::signalToRedrawTableWidget,
                     tableWgt, &CustomTableWidget::slotToDoTable);
    emit signalToRedrawTableWidget(calcAlgo->countWordLengthsSimple(TEXTEDIT_WIDGET(genWgt)->toPlainText()));
    tableWgt->show();
}

void GeneralAdapter::slotForCallBackToStartAlgorithm()
{
    //calcAlgo->inputText(genWgt->getInputWidget()->toPlainText());
    emit signalToRedrawTableWidget(calcAlgo->countWordLengthsSimple(TEXTEDIT_WIDGET(genWgt)->toPlainText()));
    //дальше тут добавляем emit signalToRedrawTableWidget(QVector<QVector<int, int>>)
    //этот сигнал связываем с tablewidget - заполняем таблицу заново
}

void GeneralAdapter::slotSetTextFromLoadTxtFile(QString text)
{
    TEXTEDIT_WIDGET(genWgt)->append(text);
}

void GeneralAdapter::slotSetTextForSaveInTxtFile()
{
    PANEL_WIDGET(genWgt)->setTextForSaving(QString(TEXTEDIT_WIDGET(genWgt)->toPlainText()));
}

void GeneralAdapter::slotCleanTextEditFromText()
{
    TEXTEDIT_WIDGET(genWgt)->clear();
}
