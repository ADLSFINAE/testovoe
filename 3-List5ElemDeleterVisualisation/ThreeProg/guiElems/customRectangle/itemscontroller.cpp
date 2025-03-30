#include "itemscontroller.h"

ItemsController::ItemsController(int N, QGraphicsRectItem *parent)
    :QGraphicsRectItem(parent)
{
    this->setRect(0, 0, 1, 1);

    initAndShowItems(N);
}

void ItemsController::initAndShowItems(int N)
{
    vecItems.resize(N + 1);
    int counter = 0;
    int yController = 0;

    bool haveArrow = true;

    for(int i = 0; i <= N; i++){
        i != N ? haveArrow = true : haveArrow = false;
        CustomRectangle* item = new CustomRectangle(QRectF(counter * 80, yController, 80, 80),
                                                    i, haveArrow, this);
        vecItems[i] = item;
        counter++;
        if(counter == 5){
            yController += 80;
            counter = 0;
        }
    }
}
