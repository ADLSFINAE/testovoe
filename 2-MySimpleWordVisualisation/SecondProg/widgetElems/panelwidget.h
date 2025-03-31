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

    QPushButton* getBtnFile() const;

    CustomButton* getBtnSetFattFormat() const;

    CustomButton* getBtnSetCursiveFormat() const;

    void setTextForSaving(QString text);

    QPushButton* getBtnOpenTable() const;

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
    QPushButton* _btnFile{nullptr};

    //Элементы выпадающего меню-бара
    QSharedPointer<QAction> _actionLoad{nullptr};

    QSharedPointer<QAction> _actionSave{nullptr};

    QSharedPointer<QAction> _actionClean{nullptr};

    //меню для компоновки QAction
    QMenu* _menu{nullptr};

    QHBoxLayout* _layout{nullptr};

    //кнопки выбора форматирования текста
    CustomButton* _btnSetFattFormat{nullptr};

    CustomButton* _btnSetCursive{nullptr};

    //кнопка открывающая кастомный QTableWidget
    QPushButton* _btnOpenTable{nullptr};

    QString _m_currentText;

};

#endif // PANELWIDGET_H
