#include "treebuilder.h"

QVector<int> TreeBuilder::parseInputString(const QString& input){

    QVector<int> treeData;
    //если человек вводит ,,  , ,  , ,  ,,, то мне нужно это предотвратить еще на стадии парсинга
    QStringList parts = input.split(',', Qt::SkipEmptyParts);

    for(const QString &part : parts){
        if (part.compare("NULL", Qt::CaseInsensitive) == 0){
            treeData.append(-1);
        }
        else{
            bool ok;
            int val = part.toInt(&ok);
            treeData.append(ok ? val : -1);
        }
    }

    return treeData;
}

TreeNode* TreeBuilder::buildFromArray(const QVector<int>& data, int idx){

    if(idx >= data.size() || data[idx] == -1){
        return nullptr;
    }

    TreeNode* node = new TreeNode(data[idx]);
    node->leftChild = buildFromArray(data, 2*idx + 1);
    node->rightChild = buildFromArray(data, 2*idx + 2);

    return node;
}

TreeNode* TreeBuilder::buildFromString(const QString& input) {

    QVector<int> treeData = parseInputString(input);

    return buildFromArray(treeData, 0);
}
