#include "generaladapter.h"

GeneralAdapter::GeneralAdapter()
{
    scene = new CustomScene(nullptr);
    view = new CustomView(scene, nullptr);
    view->show();

    itemsController = new ItemsController(19, nullptr);
    scene->addItem(itemsController);
}
