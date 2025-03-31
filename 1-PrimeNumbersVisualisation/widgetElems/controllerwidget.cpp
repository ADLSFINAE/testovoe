#include "controllerwidget.h"

ControllerWidget::ControllerWidget(QWidget *parent)
{
    this->setParent(parent);

    _btnUp = new QPushButton("Up", this);

    _btnReturn = new QPushButton("Return", this);

    _btnOnTimer = new QPushButton("On Timer", this);
    _btnOnTimer->setStyleSheet(
        "QPushButton {"
        "   background-color: #F44336;"
        "   color: white;"
        "   border-radius: 5px;"
        "   padding: 5px 10px;"
        "}"
    );

    _layout = new QVBoxLayout(this);

    _layout->addWidget(_btnUp);

    _layout->addWidget(_btnReturn);

    _layout->addWidget(_btnOnTimer);

    _layout->setSpacing(1);

    _layout->setContentsMargins(20, 20, 20, 20);

    //коннект для изменения цвета кнопки
    QObject::connect(_btnOnTimer, &QPushButton::clicked, this, &ControllerWidget::slotChangeColorBtnOnTimer);
}

QPushButton *ControllerWidget::getBtnUp() const{
    return _btnUp;
}

QPushButton *ControllerWidget::getBtnReturn() const{
    return _btnReturn;
}

QPushButton *ControllerWidget::getBtnOnTimer() const
{
    return _btnOnTimer;
}

void ControllerWidget::slotChangeColorBtnOnTimer()
{
    if(_isTimerOn){
        _btnOnTimer->setStyleSheet(
            "QPushButton {"
            "   background-color: #F44336;"
            "   color: white;"
            "   border-radius: 5px;"
            "   padding: 5px 10px;"
            "}"
        );
    }
    else{
        _btnOnTimer->setStyleSheet(
            "QPushButton {"
            "   background-color: #4CAF50;"
            "   color: white;"
            "   border-radius: 5px;"
            "   padding: 5px 10px;"
            "}"
        );
    }
    _isTimerOn = !_isTimerOn;
}



