#include "treevisualcontroller.h"

TreeVisualController::TreeVisualController(QGraphicsRectItem *parent)
    :QGraphicsRectItem(parent)
{
    this->setRect(QRectF(0, 0, 800, 800));

    //buildTree();
}

void TreeVisualController::buildTree()
{
    for(int i = 0; i < (int)vecNums.size(); i++){
        CustomEllipse* item = new CustomEllipse(QPointF(0, 0), vecNums[i], this);
        vecEllipses.append(item);
    }
    rightPlacing();
}

unsigned int TreeVisualController::findMinK(unsigned int N)
{
    if (N == 0) return 0;  // 2^0 = 1 >= 0 (если N=0, то k=0)
    if (N == 1) return 0;  // 2^0 = 1 >= 1

    unsigned int k = 0;
    unsigned int power = 1;  // 2^0 = 1

    while (power < N) {
        power <<= 1;  // Умножаем на 2 (power *= 2)
        k++;
    }

    return k;
}
#include <cmath>
#include <QGraphicsScene>
void TreeVisualController::rightPlacing()
{
    QVector<QVector<CustomEllipse*>> map;

    int k = findMinK(vecNums.size());

    map.resize(k);

    for(int i = 0; i < k; i++){
        QVector<CustomEllipse*> temp(pow(2, i), NULL);
        for(int j = 0; j < pow(2, i); j++){
            if(vecEllipses.empty()){
                break;
            }
            temp[j] = vecEllipses.first();
            vecEllipses.removeFirst();
        }
        map[i] = temp;
    }

    for(int i = 0; i < map.size(); i++){
        for(int j = 0; j < map[i].size(); j++){
            if(map[i][j] != nullptr){
                map[i][j] -> setPos((40 * j) - (20 * (pow(2, i) - 1)), (40 * i) + (20 * (pow(2, i) - 1)));
            }
            if(map[i][j] != nullptr && map[i][j]->getNumber() == -1){
                map[i][j]->hide();
            }
        }

    }



}


