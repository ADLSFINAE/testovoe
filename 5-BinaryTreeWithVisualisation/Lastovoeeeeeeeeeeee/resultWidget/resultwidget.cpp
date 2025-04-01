#include "resultwidget.h"

ResultWidget::ResultWidget(QWidget *parent)
    : QTableWidget(parent){
    setupTable();

}

void ResultWidget::setupTable(){
    setColumnCount(2);
    setHorizontalHeaderLabels({"I", "ELEMS"});

    horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

}

void ResultWidget::addResult(int number, QStringList items){
    int row = rowCount();
    insertRow(row);

    QTableWidgetItem *numberItem = new QTableWidgetItem(QString::number(number));
    numberItem->setTextAlignment(Qt::AlignCenter);
    setItem(row, 0, numberItem);

    for(auto& elem : items){
        elem.chop(1);
    }

    QTableWidgetItem *itemsItem = new QTableWidgetItem(items.join(" || "));
    setItem(row, 1, itemsItem);

}

void ResultWidget::clearResults(){
    clearContents();
    setRowCount(0);
}
