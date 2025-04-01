#ifndef TREEBUILDER_H
#define TREEBUILDER_H

#include <QVector>
#include <QObject>
#include <QStringList>

#include "treeLogic/treeNode/treenode.h"

class TreeBuilder : public QObject{
    Q_OBJECT
public:
    TreeBuilder() = default;

    TreeNode* buildFromString(const QString& input);

private:
    QVector<int> parseInputString(const QString& input);

    TreeNode* buildFromArray(const QVector<int>& data, int idx);

};

#endif // TREEBUILDER_H
