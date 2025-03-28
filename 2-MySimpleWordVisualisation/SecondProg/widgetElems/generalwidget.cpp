#include "generalwidget.h"

GeneralWidget::GeneralWidget(QWidget *parent)
    :QWidget(parent)
{
    this->setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    this->showMaximized();

    mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(5);
    mainLayout->setContentsMargins(5, 5, 5, 5);

    // Создаем и добавляем панель инструментов
    panWgt = new PanelWidget(this);
    mainLayout->addWidget(panWgt);

    // Создаем и добавляем текстовое поле
    inputWgt = new CustomTextEdit(this);
    mainLayout->addWidget(inputWgt, 1); // Аргумент 1 дает растягивание

    this->setLayout(mainLayout);

    inputWgt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

}
