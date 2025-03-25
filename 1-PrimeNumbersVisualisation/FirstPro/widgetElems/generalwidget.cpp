#include "generalwidget.h"

GeneralWidget::GeneralWidget(QWidget *parent)
    :QWidget(parent)
{
    this->setGeometry(401, 0, 400, 400);

    controllerWidget = new ControllerWidget(this);
    inputWidget = new InputWidget(this);

    layout = new QHBoxLayout(this);

    // Добавляем виджеты в layout
    layout->addWidget(inputWidget);
    layout->addWidget(controllerWidget);

    // Настройки layout (опционально)
    layout->setSpacing(20);              // Расстояние между виджетами
    layout->setContentsMargins(15, 15, 15, 15);  // Отступы от краев (left, top, right, bottom)

    // Можно настроить соотношение размеров
    layout->setStretch(0, 1);  // InputWidget получит 1 часть пространства
    layout->setStretch(1, 2);  // ControllerWidget получит 2 части
}
