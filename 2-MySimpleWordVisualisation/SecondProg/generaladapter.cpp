#include "generaladapter.h"

GeneralAdapter::GeneralAdapter()
{

    _genWgt = new GeneralWidget(nullptr);
    _genWgt->show();

    //создание таблицы
    QObject::connect(PANEL_WIDGET(_genWgt)->getBtnOpenTable(), &QPushButton::clicked,
                     this, &GeneralAdapter::slotCreateTableWidget);
    //запуск алгоритма для таблицы
    QObject::connect(TEXTEDIT_WIDGET(_genWgt), &QTextEdit::textChanged,
                     this, &GeneralAdapter::slotForCallBackToStartAlgorithm);

    //кнопки для изменения стиля
    QObject::connect(PANEL_WIDGET(_genWgt)->getBtnSetFattFormat(), &QPushButton::clicked,
                     this, &GeneralAdapter::slotToCallSetBold);

    QObject::connect(this, &GeneralAdapter::signalSetBold,
                     TEXTEDIT_WIDGET(_genWgt), &CustomTextEdit::slotSetBoldText);

    QObject::connect(PANEL_WIDGET(_genWgt)->getBtnSetCursiveFormat(), &QPushButton::clicked,
                     this, &GeneralAdapter::slotToCallSetCursive);

    QObject::connect(this, &GeneralAdapter::signalSetCursive,
                     TEXTEDIT_WIDGET(_genWgt), &CustomTextEdit::slotSetCursiveText);

    //коннект для загрузки файла
    QObject::connect(PANEL_WIDGET(_genWgt), &PanelWidget::signalTextLoadToTextEdit,
                     this, &GeneralAdapter::slotSetTextFromLoadTxtFile);

    //коннект для сохранения файла
    QObject::connect(PANEL_WIDGET(_genWgt), &PanelWidget::signalToGetTextFromTextEdit,
                     this, &GeneralAdapter::slotSetTextForSaveInTxtFile);

    //коннект для очистки бляяяяяяяяя
    QObject::connect(PANEL_WIDGET(_genWgt), &PanelWidget::signalCleanTextEdit,
                     this, &GeneralAdapter::slotCleanTextEditFromText);

    _calcAlgo = new CalcAlgorithm();

}

void GeneralAdapter::slotToCallSetBold()
{
    emit signalSetBold(PANEL_WIDGET(_genWgt)->getBtnSetFattFormat()->getIsActive());
}

void GeneralAdapter::slotToCallSetCursive()
{
    emit signalSetCursive(PANEL_WIDGET(_genWgt)->getBtnSetCursiveFormat()->getIsActive());
}

void GeneralAdapter::slotCreateTableWidget()
{
    _tableWgt = new CustomTableWidget;

    QObject::connect(this, &GeneralAdapter::signalToRedrawTableWidget,
                     _tableWgt, &CustomTableWidget::slotToDoTable);

    emit signalToRedrawTableWidget(_calcAlgo->countWordLengthsSimple(TEXTEDIT_WIDGET(_genWgt)->toPlainText()));

    _tableWgt->show();
}

void GeneralAdapter::slotForCallBackToStartAlgorithm()
{
    emit signalToRedrawTableWidget(_calcAlgo->countWordLengthsSimple(TEXTEDIT_WIDGET(_genWgt)->toPlainText()));
}

void GeneralAdapter::slotSetTextFromLoadTxtFile(QString text)
{
    TEXTEDIT_WIDGET(_genWgt)->append(text);
}

void GeneralAdapter::slotSetTextForSaveInTxtFile()
{
    PANEL_WIDGET(_genWgt)->setTextForSaving(QString(TEXTEDIT_WIDGET(_genWgt)->toPlainText()));
}

void GeneralAdapter::slotCleanTextEditFromText()
{
    TEXTEDIT_WIDGET(_genWgt)->clear();
}
