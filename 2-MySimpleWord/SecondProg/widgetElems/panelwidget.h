#ifndef PANELWIDGET_H
#define PANELWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QDir>
#include <QSharedPointer>
#include <QMessageBox>
#include <QMenu>

#include "widgetElems/buttonElems/custombutton.h"

class PanelWidget : public QWidget
{
    Q_OBJECT
public:
    PanelWidget() = default;
    PanelWidget(QWidget* parent);

    QPushButton* getBtnFile() const{return btnFile;};

    CustomButton* getBtnSetFattFormat() const{return btnSetFattFormat;};
    CustomButton* getBtnSetCursiveFormat() const{return btnSetCursive;};

    void setTextForSaving(QString text){this->m_currentText = text;};

    QPushButton* getBtnOpenTable() const{return btnOpenTable;};

signals:
    void signalTextLoadToTextEdit(QString text);
    void signalToGetTextFromTextEdit();
    void signalCleanTextEdit();

public slots:
    void slotOpenExplorerToLoad();
    void slotOpenExplorerToSave();
    void slotCleanTextEdit();

private:
    //кнопка открывающая менюху
    QPushButton* btnFile{nullptr};

    //Элементы выпадающего меню-бара
    QSharedPointer<QAction> actionLoad{nullptr};
    QSharedPointer<QAction> actionSave{nullptr};
    QSharedPointer<QAction> actionClean{nullptr};

    //менюха для компоновки QAction
    QMenu *menu{nullptr};

    QHBoxLayout* layout{nullptr};

    //кнопки выбора форматирования текста
    CustomButton* btnSetFattFormat{nullptr};
    CustomButton* btnSetCursive{nullptr};

    //кнопка открывающая кастомный QTableWidget
    QPushButton* btnOpenTable{nullptr};

private:
    QString m_currentText;
};

#endif // PANELWIDGET_H
