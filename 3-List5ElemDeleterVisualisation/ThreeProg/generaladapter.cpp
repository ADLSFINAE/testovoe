#include "generaladapter.h"

GeneralAdapter::GeneralAdapter()
{
    scene = new CustomScene(nullptr);
    view = new CustomView(scene, nullptr);
    view->show();

    algo = new ListAlgorithm();
    algo->initList(100);

    itemsController = new ItemsController(algo->getHead(), nullptr);
    scene->addItem(itemsController);

    itemsController->setRect(0, 0, 800, 100 * 80);

    QObject::connect(itemsController, &ItemsController::signalToDelete5,
                     algo, &ListAlgorithm::deleteEveryFifth);

    QObject::connect(algo, &ListAlgorithm::signalToRedrawItems,
                     itemsController, &ItemsController::initAndShowItems);

}

void GeneralAdapter::getListHead(List *head)
{
    this->head = head;
}
