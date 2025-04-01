#include "generaladapter.h"

GeneralAdapter::GeneralAdapter(QWidget *parent)
    : QWidget(parent), _root(nullptr) {
    _scene = new QGraphicsScene(this);
    createBoard();
}

void GeneralAdapter::createBoard() {
    _view = new QGraphicsView(_scene);
    _layout = new QVBoxLayout(this);

    _textEdit = new QTextEdit();
    _textEdit->setPlaceholderText("Write Some Looking Like That(1,2,3,NULL,5,6)");

    _btnHighlight = new QPushButton("Show Ways with equal depth");

    _view = new QGraphicsView(_scene);

    _layout->addWidget(_textEdit);
    _layout->addWidget(_btnHighlight);
    _layout->addWidget(_view);

    QObject::connect(_textEdit, &QTextEdit::textChanged, this, &GeneralAdapter::buildTreeFromInput);
    QObject::connect(_btnHighlight, &QPushButton::clicked, this, &GeneralAdapter::createResultWidget);

    _builder = new TreeBuilder();

    _analyzer = new TreeAnalyzer();
}

void GeneralAdapter::buildTreeFromInput() {
    clearTree(_root);
    _root = _builder->buildFromString(_textEdit->toPlainText());

    _visualisator = new TreeVisualisator(_scene);
    _visualisator->visualise(_root);
}

void GeneralAdapter::createResultWidget() {
    if (!_root){
        return;
    }

    QMap<int, QStringList> map;
    for(int i = 1; i <= _root->getHeight(_root); i++){
        QStringList tempList;
        for(auto& elem : _root->findAllPathsWithDepth(_root, i)){
            QString temp;
            for(auto& elem2 : elem){
                temp.push_back(QString::number(elem2->value));
                temp.push_back(", ");
            }

            tempList<<temp;
        }
        map[i] = tempList;
    }
    ResultWidget* resultWidget = new ResultWidget(nullptr);
    for(auto& key : map.keys()){
        if(map[key].size() >= 2){
            resultWidget->addResult(key, map[key]);
        }
    }
    resultWidget->showMaximized();

}

void GeneralAdapter::clearTree(TreeNode* node) {
    if (node) {
        clearTree(node->leftChild);
        clearTree(node->rightChild);
        delete node;
    }
}
