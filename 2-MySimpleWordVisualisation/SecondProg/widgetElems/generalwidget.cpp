#include "generalwidget.h"

GeneralWidget::GeneralWidget(QWidget *parent)
    :QWidget(parent)
{
    this->setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    this->showMaximized();

    _mainLayout = new QVBoxLayout(this);
    _mainLayout->setSpacing(5);
    _mainLayout->setContentsMargins(5, 5, 5, 5);

    // Создаем и добавляем панель инструментов
    _panWgt = new PanelWidget(this);
    _mainLayout->addWidget(_panWgt);

    // Создаем и добавляем текстовое поле
    _inputWgt = new CustomTextEdit(this);
    _mainLayout->addWidget(_inputWgt, 1); // Аргумент 1 дает растягивание

    this->setLayout(_mainLayout);

    _inputWgt->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

}

PanelWidget *GeneralWidget::getPanelWidget() const{
    return _panWgt;
}

CustomTextEdit *GeneralWidget::getInputWidget() const{
    return _inputWgt;
}
