#include "customboard.h"
#include "guiElems/customscene.h"

CustomBoard::CustomBoard(QRectF rectBoard, int N, QGraphicsRectItem *parent)
    :QGraphicsRectItem(parent)
{
    Q_UNUSED(N)
    this->setRect(rectBoard);
}

void CustomBoard::initVecBlocks(int N)
{
    //очистка доски и вектора для новых данных
    if(vecBlocks.size() > 0){
        for(auto& elem : vecBlocks)
            this->scene()->removeItem(elem);

        vecBlocks.clear();
    }

    //заполнение доски
    N++;
    vecBlocks.resize(N);
    int iterX = 0;
    int iterY = 0;
    for(int i = 0; i < N; i++){
        CustomBlock* block = new CustomBlock(iterX, iterY, i, this);
        iterX++;
        if(iterX == 10){
            iterX = 0;
            iterY++;
        }
        vecBlocks[i] = block;
    }

}
