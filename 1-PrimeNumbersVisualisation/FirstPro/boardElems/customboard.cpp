#include "customboard.h"

CustomBoard::CustomBoard(QRectF rectBoard, int N, QGraphicsRectItem *parent)
{
    this->setRect(rectBoard);
    if(N != 0){
        N++;
    }
    if(N > 201){

    }
    else{
        vecBlocks.resize(N);
        initVecBlocks(N);
    }



}

void CustomBoard::initVecBlocks(int N)
{

    int iterX = 0;
    int iterY = 0;
    for(int i = 2; i < N; i++){
        CustomBlock* block = new CustomBlock(iterX, iterY, i, this);
        iterX++;
        if(iterX == 10){
            iterX = 0;
            iterY++;
        }
        vecBlocks[i] = block;
    }
}
