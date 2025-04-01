#include "treenode.h"

TreeNode::TreeNode(int val)
    : value(val){

}

void TreeNode::findPathsWithDepthHelper(TreeNode *node, int currentDepth,
                                        int targetDepth, QVector<TreeNode *> &currentPath,
                                        QVector<QVector<TreeNode *> > &result){
    if (!node) return;

    // Добавляем текущий узел в путь
    currentPath.push_back(node);

    // Если достигли нужной глубины
    if (currentDepth == targetDepth) {
        result.push_back(currentPath);
    }
    else {
        // Рекурсивно ищем в поддеревьях
        findPathsWithDepthHelper(node->leftChild, currentDepth + 1, targetDepth, currentPath, result);
        findPathsWithDepthHelper(node->rightChild, currentDepth + 1, targetDepth, currentPath, result);
    }

    // Убираем узел из пути перед возвратом
    currentPath.pop_back();
}

int TreeNode::getHeight(const TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = getHeight(root->leftChild);
    int rightHeight = getHeight(root->rightChild);

    return 1 + qMax(leftHeight, rightHeight);
}

QVector<QVector<TreeNode *> > TreeNode::findAllPathsWithDepth(TreeNode *root, int targetDepth) {
    QVector<QVector<TreeNode*>> result;
    QVector<TreeNode*> currentPath;
    findPathsWithDepthHelper(root, 1, targetDepth, currentPath, result);
    return result;
}
