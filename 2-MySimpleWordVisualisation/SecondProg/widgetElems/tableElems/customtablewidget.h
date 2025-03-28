#ifndef CUSTOMTABLEWIDGET_H
#define CUSTOMTABLEWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QHeaderView>

class CustomTableWidget : public QTableWidget
{
    Q_OBJECT
public:
    CustomTableWidget(QTableWidget* parent = nullptr);
public slots:
    void slotToDoTable(QMap<int, int> stats);
private:
    QStringList headers;

    QTableWidgetItem* lengthItem{nullptr};
    QTableWidgetItem* countItem{nullptr};
};

#endif // CUSTOMTABLEWIDGET_H
