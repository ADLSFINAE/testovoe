#include "generaladapter.h"

GeneralAdapter::GeneralAdapter()
{
    scene = new CustomScene(GlobVal::sceneRect, nullptr);
    view = new CustomView(GlobVal::viewRect, scene, nullptr);
    view->show();

    boardSolver = new CustomBoard(GlobVal::boardSolver, 200, nullptr);
    scene->addItem(boardSolver);

    generalWidget = new GeneralWidget(nullptr);
    generalWidget->setGeometry(401, 0, 400, 100);
    scene->addWidget(generalWidget);
    generalWidget->show();

    answerTextEdit = new AnswerTextEdit(nullptr);
    scene->addWidget(answerTextEdit);
    answerTextEdit->setGeometry(401, 110, 400, 700);
    answerTextEdit->show();

    //коннект для инициализации доски значениями и ее отчистки от старый значений
    QObject::connect(generalWidget->getInputWidget(), &InputWidget::numberSubmitted,
                     boardSolver, &CustomBoard::initVecBlocks);

    QObject::connect(boardSolver, &CustomBoard::signalToSendPrimeNumber,
                     answerTextEdit, &AnswerTextEdit::appendOutput);


}

void GeneralAdapter::cleanVecBlocks(QVector<CustomBlock *> vecBlocks)
{
    qDebug()<<vecBlocks.size();
    QVector<CustomBlock*> vec = vecBlocks;
    for(auto& elem : vec){
        elem->hide();
    }
}
