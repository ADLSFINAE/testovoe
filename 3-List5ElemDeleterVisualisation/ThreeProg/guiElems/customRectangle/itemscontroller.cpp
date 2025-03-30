#include "itemscontroller.h"
#include <QDebug>

ItemsController::ItemsController(List* head, QGraphicsRectItem *parent)
    :QGraphicsRectItem(parent)
{
    this->head = head;
    initAndShowItems(head);
}

void ItemsController::initAndShowItems(List* head)
{
    qDebug()<<"was called";
    if(vecItems.size() != 0){
        for(auto& elem : vecItems){
            this->scene()->removeItem(elem);
        }
        vecItems.clear();
    }

    if(head != nullptr){
        qDebug()<<head->payload;
        int counter = 0;
        int yController = 0;

        bool haveArrow = true;

        while(head != nullptr){
            if(head->next == nullptr){
                haveArrow = false;
            }
            CustomRectangle* item = new CustomRectangle(QRectF(counter * 80, yController, 80, 80),
                                                        head->payload, haveArrow, this);
            vecItems.push_back(item);
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
    qDebug()<<"happens";
    emit signalToDelete5(head);
    this->setPos(0, 0);
    if((((vecItems.size() / 5 * 4) + 1) * 40) >= 80){
        this->setRect(0, 0, 800, (((vecItems.size() / 5 * 4) + 1) * 40) + 40);
    }
    event->accept();
}

void ItemsController::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    if(event->delta() < 0){
        this->setPos(0, this->pos().y() - 40);
    }
    else{
        this->setPos(0, this->pos().y() + 40);
    }

    event->accept();
}

void ItemsController::setListHead(List* head)
{
    this->head = head;
}
