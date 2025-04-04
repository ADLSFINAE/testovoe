#include "customtablewidget.h"

CustomTableWidget::CustomTableWidget(QTableWidget* parent)
    :QTableWidget(parent)
{
    setColumnCount(2);
    setSelectionMode(QAbstractItemView::SingleSelection);

    headers << "Длина слова" << "Количество";
    setHorizontalHeaderLabels(headers);

}

void CustomTableWidget::slotToDoTable(QMap<int, int> stats)
{
    clearContents(); // Очищаем предыдущие данные

    // Настройка внешнего вида
    horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    verticalHeader()->setVisible(false);
    setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Устанавливаем количество строк
    setRowCount(stats.size());

    int row = 0;
    for (auto it = stats.begin(); it != stats.end(); ++it) {
        // Длина слова
        lengthItem = new QTableWidgetItem(QString::number(it.key()));
        lengthItem->setTextAlignment(Qt::AlignCenter | Qt::AlignTop | Qt::AlignLeft);
        setItem(row, 0, lengthItem);

        // Количество
        countItem = new QTableWidgetItem(QString::number(it.value()));
        countItem->setTextAlignment(Qt::AlignCenter | Qt::AlignTop | Qt::AlignRight);
        setItem(row, 1, countItem);

        row++;
    }

    // Сортировка
    sortByColumn(0, Qt::AscendingOrder);

    // Автоподбор размера
    resizeColumnsToContents();
    resizeRowsToContents();
}
