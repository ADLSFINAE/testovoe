#ifndef PANELWIDGET_H
#define PANELWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QDir>
#include <QSharedPointer>
#include <QMessageBox>

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

    QPushButton* getBtnOpenTable() const{return btnOpenTable;};

public slots:
    void slotOpenExplorerToLoad();
    void slotOpenExplorerToSave();
private:
    QPushButton* btnFile{nullptr};

    CustomButton* btnSetFattFormat{nullptr};
    CustomButton* btnSetCursive{nullptr};

    QPushButton* btnOpenTable{nullptr};

    QSharedPointer<QAction> actionLoad{nullptr};
    QSharedPointer<QAction> actionSave{nullptr};
    QSharedPointer<QAction> actionClean{nullptr};

    QMenu *menu{nullptr};

    QHBoxLayout* layout{nullptr};
};

#endif // PANELWIDGET_H
