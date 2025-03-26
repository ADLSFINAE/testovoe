#include "generalwidget.h"

GeneralWidget::GeneralWidget(QWidget *parent)
    :QWidget(parent)
{
    this->setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    this->showMaximized();

    // Создаем главный вертикальный layout
    mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(5); // Расстояние между виджетами
    mainLayout->setContentsMargins(5, 5, 5, 5); // Отступы от краев

    // Создаем и добавляем панель инструментов
    panWgt = new PanelWidget(this);
    mainLayout->addWidget(panWgt);

    // Создаем и добавляем текстовое поле (с растягиванием)
    inputWgt = new CustomTextEdit(this);
    mainLayout->addWidget(inputWgt, 1); // Аргумент 1 дает растягивание

    // Устанавливаем layout для виджета
    this->setLayout(mainLayout);

    // Дополнительные настройки
    inputWgt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

}
