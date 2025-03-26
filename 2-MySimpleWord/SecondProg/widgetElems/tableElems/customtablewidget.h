#ifndef CUSTOMTABLEWIDGET_H
#define CUSTOMTABLEWIDGET_H

#include <QWidget>
#include <QTableWidget>

class CustomTableWidget : public QTableWidget
{
    Q_OBJECT
public:
    CustomTableWidget();
public slots:
    void slotToDoTable(QMap<int, int> stats);
};

#endif // CUSTOMTABLEWIDGET_H
