#include "customtablewidget.h"

CustomTableWidget::CustomTableWidget()
{
    this->setParent(nullptr);
    setColumnCount(2);
    setSelectionMode(QAbstractItemView::SingleSelection);

    QStringList headers;
    headers << "Длина слова" << "Количество";
    setHorizontalHeaderLabels(headers);

}
#include <QHeaderView>
void CustomTableWidget::slotToDoTable(QMap<int, int> stats)
{
    clearContents(); // Очищаем предыдущие данные

        // Настройка внешнего вида
        horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        verticalHeader()->setVisible(false);
        setEditTriggers(QAbstractItemView::NoEditTriggers);

        // Устанавливаем количество строк
        setRowCount(stats.size());

        // Заполнение данными
        int row = 0;
        for (auto it = stats.begin(); it != stats.end(); ++it) {
            // Длина слова
            QTableWidgetItem* lengthItem = new QTableWidgetItem(QString::number(it.key()));
            lengthItem->setTextAlignment(Qt::AlignCenter);
            setItem(row, 0, lengthItem);

            // Количество
            QTableWidgetItem* countItem = new QTableWidgetItem(QString::number(it.value()));
            countItem->setTextAlignment(Qt::AlignCenter);
            setItem(row, 1, countItem);

            row++;
        }

        // Сортировка
        sortByColumn(0, Qt::AscendingOrder);

        // Автоподбор размера
        resizeColumnsToContents();
        resizeRowsToContents();
}
