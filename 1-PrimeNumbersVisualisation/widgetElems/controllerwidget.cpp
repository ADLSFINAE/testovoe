#include "controllerwidget.h"

ControllerWidget::ControllerWidget(QWidget *parent)
{
    this->setParent(parent);

    // Создаем кнопки
    btnUp = new QPushButton("Up", this);
    btnReturn = new QPushButton("Return", this);

    // Создаем вертикальный layout
    layout = new QVBoxLayout(this);

    // Добавляем кнопки в layout
    layout->addWidget(btnUp);
    layout->addWidget(btnReturn);

    // Опциональные настройки
    layout->setSpacing(1); // Расстояние между кнопками
    layout->setContentsMargins(20, 20, 20, 20); // Отступы от краев виджета

    this->show();
}



