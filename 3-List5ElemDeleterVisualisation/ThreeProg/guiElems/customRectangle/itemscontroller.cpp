#include "itemscontroller.h"
#include <QDebug>

ItemsController::ItemsController(List* head, QGraphicsRectItem *parent)
    :QGraphicsRectItem(parent)
{
    this->_head = head;
    initAndShowItems(_head);
}

void ItemsController::initAndShowItems(List* head)
{
    if(_vecItems.size() != 0){
        for(auto& elem : _vecItems){
            this->scene()->removeItem(elem);
        }
        _vecItems.clear();
    }

    if(head != nullptr){
        int counter = 0;

        int yController = 0;

        bool haveArrow = true;

        while(head != nullptr){
            if(head->next == nullptr)
                haveArrow = false;

            CustomRectangle* item = new CustomRectangle(QRectF(counter * 80, yController, 80, 80),
                                                        head->payload, haveArrow, this);

            _vecItems.push_back(item);

            counter++;

            if(counter == 5){
                yController += 80;
                counter = 0;
            }

            head = head->next;

        }
    }
}

void ItemsController::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit signalToDelete5(_head);

    this->setPos(0, 0);

    int generalRectHeight = ((_vecItems.size() / 5 * 4) + 1) * 40;

    if(generalRectHeight >= 80)
        this->setRect(0, 0, 800, (generalRectHeight * 40) + 40);

    event->accept();
}

void ItemsController::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    event->delta() < 0 ? this->setPos(0, this->pos().y() - 40) : this->setPos(0, this->pos().y() + 40);

    event->accept();
}

void ItemsController::setListHead(List* head)
{
    this->_head = head;
}
