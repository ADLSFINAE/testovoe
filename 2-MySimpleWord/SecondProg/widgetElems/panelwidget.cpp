#include "panelwidget.h"
#include <QMenu>
PanelWidget::PanelWidget(QWidget *parent)
{
    this->setParent(parent);
    this->show();

    btnFile = new QPushButton("File", this);

    btnSetFattFormat = new CustomButton("Жирный", this);
    btnSetCursive = new CustomButton("Курсив", this);
    btnSetUnderLine = new CustomButton("Подчёркивание", this);

    btnOpenTable = new QPushButton("TRIE ALGO", this);

    //коннекты для смены цвета - индикация состояния
    QObject::connect(btnSetFattFormat, &QPushButton::clicked, btnSetFattFormat, &CustomButton::changeIsActive);
    QObject::connect(btnSetCursive, &QPushButton::clicked, btnSetCursive, &CustomButton::changeIsActive);
    QObject::connect(btnSetUnderLine, &QPushButton::clicked, btnSetUnderLine, &CustomButton::changeIsActive);

    layout = new QHBoxLayout(this);

    layout->setSpacing(1);
    layout->setContentsMargins(0, 0, 0, 0);

    layout->addWidget(btnFile);
    layout->addWidget(btnSetFattFormat);
    layout->addWidget(btnSetCursive);
    layout->addWidget(btnSetUnderLine);
    layout->addWidget(btnOpenTable);

    // Выравнивание влево и вверх
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    // Фиксируем минимальную высоту панели
    setMinimumHeight(btnFile->sizeHint().height());

    // Привязываем размер панели к содержимому
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    menu = new QMenu(this);

    actionLoad = QSharedPointer<QAction>(new QAction(QString("Загрузить"), menu));
    actionSave =  QSharedPointer<QAction>( new QAction(QString("Сохранить"), menu));
    actionClean =  QSharedPointer<QAction>(new QAction(QString("Очистить"), menu));

    menu->addAction(actionLoad.data());
    menu->addAction(actionSave.data());
    menu->addAction(actionClean.data());

    QObject::connect(actionLoad.data(), &QAction::triggered, this, &PanelWidget::slotOpenExplorerToLoad);
    QObject::connect(actionSave.data(), &QAction::triggered, this, &PanelWidget::slotOpenExplorerToSave);

    btnFile->setMenu(menu);
}

void PanelWidget::slotOpenExplorerToSave()
{
    //мем для тестаааааааа
    QString m_currentText = "daskdaslda;slkdk;asd";
    QString m_currentFile;
    // Открываем диалог сохранения файла
    QString filePath = QFileDialog::getSaveFileName(
                this,
                tr("Сохранить файл"),
                QDir::homePath() + "/untitled.txt",  // Начальное имя файла
                tr("Текстовые файлы (*.txt);;Все файлы (*)") // Фильтры
                );

    // Если пользователь не отменил диалог
    if (!filePath.isEmpty()) {
        QFile file(filePath);

        // Пытаемся открыть файл для записи
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << m_currentText;  // Записываем текст в файл
            file.close();

            m_currentFile = filePath; // Сохраняем текущий путь
            qDebug() << "Файл сохранен:" << filePath;

            QMessageBox::information(this, "Успех", "Файл успешно сохранен!");
        } else {
            QMessageBox::critical(this, "Ошибка",
                                  "Не удалось сохранить файл!\n" + file.errorString());
        }
    }
}

void PanelWidget::slotOpenExplorerToLoad()
{
    QString filePath = QFileDialog::getOpenFileName(
            this,
            "Выберите файл",
            QDir::homePath(),
            "Все файлы (*.*);;Текстовые файлы (*.txt);;Изображения (*.png *.jpg *.bmp)");

        if (!filePath.isEmpty()) {
            qDebug() << "Выбран файл:" << filePath;
            // Здесь можно добавить обработку выбранного файла
            // Например, emit signalFileSelected(filePath);
        }
}

