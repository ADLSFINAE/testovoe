#include "panelwidget.h"

PanelWidget::PanelWidget(QWidget *parent)
{
    this->setParent(parent);
    this->show();

    //Объявление кнопки File и создание выпадающего списка
    _btnFile = new QPushButton("File", this);

    _menu = new QMenu(this);

    _actionLoad = QSharedPointer<QAction>(new QAction(QString("Загрузить"), _menu));

    _actionSave =  QSharedPointer<QAction>( new QAction(QString("Сохранить"), _menu));

    _actionClean =  QSharedPointer<QAction>(new QAction(QString("Очистить"), _menu));

    _menu->addAction(_actionLoad.data());

    _menu->addAction(_actionSave.data());

    _menu->addAction(_actionClean.data());

    //коннекты Action'ов для индексации нажатий и последующих эмитов других функций
    QObject::connect(_actionLoad.data(), &QAction::triggered, this, &PanelWidget::slotOpenExplorerToLoad);

    QObject::connect(_actionSave.data(), &QAction::triggered, this, &PanelWidget::slotOpenExplorerToSave);

    QObject::connect(_actionClean.data(), &QAction::triggered, this, &PanelWidget::slotCleanTextEdit);

    _btnFile->setMenu(_menu);

    //кнопки изменяющие стиль
    _btnSetFattFormat = new CustomButton("Fatt", this);

    _btnSetCursive = new CustomButton("Cursive", this);

    _btnOpenTable = new QPushButton("Live-Result", this);

    //коннекты для смены цвета - индикация состояния
    QObject::connect(_btnSetFattFormat, &QPushButton::clicked, _btnSetFattFormat, &CustomButton::changeIsActive);

    QObject::connect(_btnSetCursive, &QPushButton::clicked, _btnSetCursive, &CustomButton::changeIsActive);

    _layout = new QHBoxLayout(this);

    _layout->addWidget(_btnFile);
    _layout->addWidget(_btnSetFattFormat);
    _layout->addWidget(_btnSetCursive);
    _layout->addWidget(_btnOpenTable);

    // Выравнивание влево и вверх
    _layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    // Фиксируем минимальную высоту панели
    setMinimumHeight(_btnFile->sizeHint().height());

    // Привязываем размер панели к содержимому
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

}

QPushButton *PanelWidget::getBtnFile() const{
    return _btnFile;
}

CustomButton *PanelWidget::getBtnSetFattFormat() const{
    return _btnSetFattFormat;
}

CustomButton *PanelWidget::getBtnSetCursiveFormat() const{
    return _btnSetCursive;
}

void PanelWidget::setTextForSaving(QString text){
    this->_m_currentText = text;
}

QPushButton *PanelWidget::getBtnOpenTable() const{
    return _btnOpenTable;
}

void PanelWidget::slotOpenExplorerToSave()
{
    emit signalToGetTextFromTextEdit();

    QString m_currentFile;
    // Открываем диалог сохранения файла
    QString filePath = QFileDialog::getSaveFileName(
                this,
                tr("Сохранить файл"),
                QDir::homePath() + "/untitled.txt",  // Начальное имя файла
                tr("Текстовые файлы (*.txt);") // Фильтры
                );

    // Если пользователь не отменил диалог
    if (!filePath.isEmpty()) {
        QFile file(filePath);

        // Пытаемся открыть файл для записи
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << _m_currentText;  // Записываем текст в файл
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
    this->_m_currentText.clear();

    emit signalCleanTextEdit();
}

void PanelWidget::slotOpenExplorerToLoad()
{
    QString filePath = QFileDialog::getOpenFileName(
                this,
                "Выберите файл",
                QDir::homePath(),
                "Текстовые файлы (*.txt);");

    if (!filePath.isEmpty()) {

        QFile file(filePath);

        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {

            // Вариант 1: Чтение всего файла сразу
            QString fileContent = QString::fromUtf8(file.readAll());

            file.close();

            emit signalTextLoadToTextEdit(fileContent); // Сигнал с содержимым файла

            // Вариант 2: Построчное чтение (для больших файлов)
            /*
                QTextStream in(&file);
                in.setCodec("UTF-8");
                QStringList lines;
                while (!in.atEnd()) {
                    lines << in.readLine();
                }
                file.close();
                QString fileContent = lines.join("\n");
                */
        } else {
            QMessageBox::critical(this, "Ошибка",
                                  "Не удалось открыть файл:\n" + file.errorString());
        }
    }
}

