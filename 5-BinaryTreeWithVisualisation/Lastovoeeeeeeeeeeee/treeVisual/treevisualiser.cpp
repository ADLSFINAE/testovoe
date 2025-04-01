#include "treevisualiser.h"

TreeVisualisator::TreeVisualisator(QGraphicsScene* scene)
    : _scene(scene){

}

void TreeVisualisator::visualise(TreeNode* root){
    clear();
    if(root){
        drawTree(root, 0, _scene->width()/2, _scene->width()/4);
    }
}

void TreeVisualisator::drawTree(TreeNode* node, int level, int x, int offset){
    if(!node){
        return;
    }

    int y = level * 160;
    drawNode(node, x, y);

    if(node->leftChild){
        int fromX = x;
        int fromY = y;

        int toX = x - offset;
        int toY = y + 160;

        drawEdge(fromX, fromY, toX, toY);
        drawTree(node->leftChild, level + 1, x - offset, offset / 2);
    }

    if(node->rightChild){
        int fromX = x;
        int fromY = y;

        int toX = x + offset;
        int toY = y + 160;

        drawEdge(fromX, fromY, toX, toY);
        drawTree(node->rightChild, level + 1, x + offset, offset / 2);
    }
}

void TreeVisualisator::drawNode(TreeNode* node, int x, int y){
    QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem(x-40, y-40, 80, 80);
    ellipse->setBrush(Qt::white);
    ellipse->setPen(QPen(Qt::black, 2));
    _scene->addItem(ellipse);
    nodeItems[node] = ellipse;

    QGraphicsTextItem* text = new QGraphicsTextItem(QString::number(node->value));
    text->setPos(x - text->boundingRect().width()/2, y - text->boundingRect().height()/2);
    _scene->addItem(text);
}

void TreeVisualisator::drawEdge(int fromX, int fromY, int toX, int toY) {
    QGraphicsLineItem* line = new QGraphicsLineItem();

    QPointF normaliseVector(toX - fromX, toY - fromY);
    float length = sqrt(normaliseVector.x() * normaliseVector.x() + normaliseVector.y() * normaliseVector.y());
    normaliseVector = {normaliseVector.x() / length, normaliseVector.y() / length}; //

    /*Выполнив я получу вектор направления, куда нужно строиться
     *  и домножая на половину радиуса - получу координаты

    По сути я просто поделил скалярное значение каждой координаты на длину самого вектора,
    а длина такого вектора равна единице*/

    QPointF start(fromX + normaliseVector.x() * 40, fromY + normaliseVector.y() * 40);

    QPointF end(toX - normaliseVector.x() * 40, toY - normaliseVector.y() * 40);

    line->setLine(QLineF(start, end));
    line->setPen(QPen(Qt::black, 2));
    _scene->addItem(line);
}

void TreeVisualisator::clear() {
    nodeItems.clear();
    _scene->clear();
}
