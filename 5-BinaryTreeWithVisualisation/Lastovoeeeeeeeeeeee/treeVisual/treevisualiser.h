#ifndef TREEVISUALIZER_H
#define TREEVISUALIZER_H

#include <QGraphicsScene>
#include <QHash>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QPen>
#include <QMap>

#include "treeLogic/treeNode/treenode.h"
#include <QObject>

class TreeVisualisator : public QObject{
    Q_OBJECT
public:
    TreeVisualisator() = default;

    TreeVisualisator(QGraphicsScene* scene);

    void visualise(TreeNode* root);

    void clear();

private:
    //штуки для отрисовки графики вызываются в visualise
    void drawTree(TreeNode* node, int level, int x, int offset);

    void drawNode(TreeNode* node, int x, int y);

    void drawEdge(int x1, int y1, int x2, int y2);

private:
    QGraphicsScene* _scene{nullptr};
    QMap<TreeNode*, QGraphicsEllipseItem*> nodeItems;
};

#endif // TREEVISUALIZER_H
