#include "controllerwidget.h"

ControllerWidget::ControllerWidget(QWidget *parent)
{
    this->setParent(parent);

    btnUp = new QPushButton("Up", this);

    btnReturn = new QPushButton("Return", this);

    btnOnTimer = new QPushButton("On Timer", this);
    btnOnTimer->setStyleSheet(
        "QPushButton {"
        "   background-color: #F44336;"
        "   color: white;"
        "   border-radius: 5px;"
        "   padding: 5px 10px;"
        "}"
    );

    layout = new QVBoxLayout(this);

    layout->addWidget(btnUp);

    layout->addWidget(btnReturn);

    layout->addWidget(btnOnTimer);

    layout->setSpacing(1);

    layout->setContentsMargins(20, 20, 20, 20);

    //коннект для изменения цвета кнопки
    QObject::connect(btnOnTimer, &QPushButton::clicked, this, &ControllerWidget::slotChangeColorBtnOnTimer);
}

QPushButton *ControllerWidget::getBtnUp() const{
    return btnUp;
}

QPushButton *ControllerWidget::getBtnReturn() const{
    return btnReturn;
}

QPushButton *ControllerWidget::getBtnOnTimer() const
{
    return btnOnTimer;
}

void ControllerWidget::slotChangeColorBtnOnTimer()
{
    if(isTimerOn){
        btnOnTimer->setStyleSheet(
            "QPushButton {"
            "   background-color: #F44336;"  // Красный фон (как в Material Design)
            "   color: white;"               // Белый текст
            "   border-radius: 5px;"         // Скругленные углы
            "   padding: 5px 10px;"          // Отступы внутри
            "}"
        );
        isTimerOn = !isTimerOn;
    }
    else{
        btnOnTimer->setStyleSheet(
            "QPushButton {"
            "   background-color: #4CAF50;"
            "   color: white;"
            "   border-radius: 5px;"
            "   padding: 5px 10px;"
            "}"
        );
        isTimerOn = !isTimerOn;
    }
}



