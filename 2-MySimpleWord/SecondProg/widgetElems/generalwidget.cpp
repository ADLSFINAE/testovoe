#include "generalwidget.h"

GeneralWidget::GeneralWidget(QWidget *parent)
    :QWidget(parent)
{
    this->setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    this->showMaximized();


}
