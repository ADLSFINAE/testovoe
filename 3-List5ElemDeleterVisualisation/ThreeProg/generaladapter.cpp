#include "generaladapter.h"

GeneralAdapter::GeneralAdapter()
{
    _inputWidget = new InputWidget(nullptr);
    _inputWidget->show();

    QObject::connect(_inputWidget->getInputButton(), &QPushButton::clicked,
                     this, &GeneralAdapter::setNumberOfListElems);
}

void GeneralAdapter::getListHead(List *head)
{
    this->_head = head;
}

void GeneralAdapter::setNumberOfListElems()
{
    int N = _inputWidget->getInputText();
    if(N <= 1000 && N >= 1){
        _scene = new CustomScene(nullptr);
        _view = new CustomView(_scene, nullptr);
        _view->show();

        _algo = new ListAlgorithm();
        _algo->initList(N);

        _itemsController = new ItemsController(_algo->getHead(), nullptr);
        _itemsController->setRect(0, 0, 800, N * 80);
        _scene->addItem(_itemsController);

        QObject::connect(_itemsController, &ItemsController::signalToDelete5,
                         _algo, &ListAlgorithm::deleteEveryFifth);

        QObject::connect(_algo, &ListAlgorithm::signalToRedrawItems,
                         _itemsController, &ItemsController::initAndShowItems);
    }
    else{
        QMessageBox::warning(nullptr, "Error",
                             QString("Please enter a number between 1 and %1").arg(1000));

    }
}
