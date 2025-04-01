#ifndef RESULTWIDGET_H
#define RESULTWIDGET_H

#include <QTableWidget>
#include <QHeaderView>

class ResultWidget : public QTableWidget
{
    Q_OBJECT
public:
    ResultWidget() = default;

    ResultWidget(QWidget *parent = nullptr);

    void addResult(int number, QStringList items);

    void clearResults();

private:
    void setupTable();

};

#endif // RESULTWIDGET_H
