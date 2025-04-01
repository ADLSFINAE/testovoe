#include "treeanalysator.h"

void TreeAnalyzer::findPathsRecursive(TreeNode* node, QVector<TreeNode*>& currentPath,
                                    QVector<QVector<TreeNode*>>& allPaths, int targetDepth) {
    if (!node) return;

    currentPath.append(node);

    if (currentPath.size() == targetDepth) {
        allPaths.append(currentPath);
    } else {
        findPathsRecursive(node->leftChild, currentPath, allPaths, targetDepth);
        findPathsRecursive(node->rightChild, currentPath, allPaths, targetDepth);
    }

    currentPath.removeLast();
}

QVector<QVector<TreeNode*>> TreeAnalyzer::findPathsToDepth(TreeNode* root, int targetDepth) {
    QVector<QVector<TreeNode*>> allPaths;
    QVector<TreeNode*> currentPath;
    findPathsRecursive(root, currentPath, allPaths, targetDepth);
    return allPaths;
}
