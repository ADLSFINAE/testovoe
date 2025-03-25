#include "controllerwidget.h"

ControllerWidget::ControllerWidget(QWidget *parent)
{
    this->setParent(parent);

    // Создаем кнопки
    btnInstaResult = new QPushButton("Instant Result", this);

    // Создаем вертикальный layout
    layout = new QVBoxLayout(this);

    // Добавляем кнопки в layout
    layout->addWidget(btnInstaResult);

    // Опциональные настройки
    layout->setSpacing(1); // Расстояние между кнопками
    layout->setContentsMargins(20, 20, 20, 20); // Отступы от краев виджета

    this->show();
}



