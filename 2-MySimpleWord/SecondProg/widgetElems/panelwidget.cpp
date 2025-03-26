#include "panelwidget.h"
#include <QMenu>
PanelWidget::PanelWidget(QWidget *parent)
{
    this->setParent(parent);
    this->show();

    btnFile = new QPushButton("File", this);

    btnSetFattFormat = new CustomButton("Жирный", this);
    btnSetCursive = new CustomButton("Курсив", this);

    btnOpenTable = new QPushButton("TRIE ALGO", this);

    //коннекты для смены цвета - индикация состояния
    QObject::connect(btnSetFattFormat, &QPushButton::clicked, btnSetFattFormat, &CustomButton::changeIsActive);
    QObject::connect(btnSetCursive, &QPushButton::clicked, btnSetCursive, &CustomButton::changeIsActive);

    layout = new QHBoxLayout(this);

    layout->setSpacing(1);
    layout->setContentsMargins(0, 0, 0, 0);

    layout->addWidget(btnFile);
    layout->addWidget(btnSetFattFormat);
    layout->addWidget(btnSetCursive);
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

    //коннекты Action'ов для индексации нажатий и последующих эмитов других функций
    QObject::connect(actionLoad.data(), &QAction::triggered, this, &PanelWidget::slotOpenExplorerToLoad);
    QObject::connect(actionSave.data(), &QAction::triggered, this, &PanelWidget::slotOpenExplorerToSave);
    QObject::connect(actionClean.data(), &QAction::triggered, this, &PanelWidget::slotCleanTextEdit);

    btnFile->setMenu(menu);
}

void PanelWidget::slotOpenExplorerToSave()
{
    //мем для тестаааааааа
    emit signalToGetTextFromTextEdit();
    //чтобы заполнить эту штуковину, нужно предпринять emit
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

void PanelWidget::slotCleanTextEdit()
{
    this->m_currentText.clear();
    emit signalCleanTextEdit();
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

        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            // Вариант 1: Чтение всего файла сразу
            QString fileContent = QString::fromUtf8(file.readAll());
            file.close();

            qDebug() << "Содержимое файла:" << fileContent;
            emit signalTextLoadToTextEdit(fileContent); // Сигнал с содержимым файла

            // Вариант 2: Построчное чтение (для больших файлов)
            /*
                QTextStream in(&file);
                in.setCodec("UTF-8"); // Установка кодировки
                QStringList lines;
                while (!in.atEnd()) {
                    lines << in.readLine();
                }
                file.close();
                QString fileContent = lines.join("\n");
                */
        } else {
            qDebug() << "Ошибка открытия файла:" << file.errorString();
            QMessageBox::critical(this, "Ошибка",
                                  "Не удалось открыть файл:\n" + file.errorString());
        }
    }
}

