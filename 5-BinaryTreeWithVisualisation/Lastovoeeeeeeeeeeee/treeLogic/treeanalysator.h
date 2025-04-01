#ifndef TREEANALYZER_H
#define TREEANALYZER_H

#include "treeLogic/treeNode/treenode.h"
#include <QVector>
#include <QObject>

class TreeAnalyzer : public QObject{

    Q_OBJECT

public:
    QVector<QVector<TreeNode*>> findPathsToDepth(TreeNode* root, int targetDepth);

private:
    void findPathsRecursive(TreeNode* node, QVector<TreeNode*>& currentPath,
                                 QVector<QVector<TreeNode*>>& allPaths, int targetDepth);
};

#endif // TREEANALYZER_H
