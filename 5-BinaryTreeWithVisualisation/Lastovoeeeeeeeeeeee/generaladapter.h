#ifndef BINARYTREEVIEWER_H
#define BINARYTREEVIEWER_H

#include <QVBoxLayout>
#include <QWidget>
#include <QMap>
#include <QString>
#include <QStringList>
#include <QWidget>
#include <QGraphicsView>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>

#include "resultWidget/resultwidget.h"

#include "treeLogic/treeNode/treenode.h"
#include "treeLogic/treeanalysator.h"

#include "treeVisual/treebuilder.h"
#include "treeVisual/treevisualiser.h"

class GeneralAdapter : public QWidget {
    Q_OBJECT
public:
    GeneralAdapter() = default;
    GeneralAdapter(QWidget *parent = nullptr);

private slots:
    void buildTreeFromInput();
    void createResultWidget();

private:
    void createBoard();

    void clearTree(TreeNode* node);

private:
    QGraphicsScene* _scene{nullptr};

    QGraphicsView* _view{nullptr};

    QTextEdit* _textEdit{nullptr};

    QPushButton* _btnHighlight{nullptr};

    TreeNode* _root{nullptr};

    TreeBuilder* _builder{nullptr};

    TreeAnalyzer* _analyzer{nullptr};

    TreeVisualisator* _visualisator{nullptr};

    QVBoxLayout* _layout{nullptr};
};

#endif // BINARYTREEVIEWER_H
