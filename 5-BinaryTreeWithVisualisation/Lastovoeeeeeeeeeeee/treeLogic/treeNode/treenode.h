#ifndef TREENODE_H
#define TREENODE_H

#include <QVector>

struct TreeNode {
    //моя вставка для удобства
    TreeNode() = default;

    TreeNode(int val);

    void findPathsWithDepthHelper(TreeNode* node, int currentDepth, int targetDepth,
                                  QVector<TreeNode*>& currentPath, QVector<QVector<TreeNode*>>& result);

    int getHeight(const TreeNode* root);

    QVector<QVector<TreeNode*>> findAllPathsWithDepth(TreeNode* root, int targetDepth);
    ////////////////////

    int value = 0;

    struct TreeNode* leftChild{nullptr};

    struct TreeNode* rightChild{nullptr};

};
#endif // TREENODE_H
