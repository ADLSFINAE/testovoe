#include "generaladapter.h"

GeneralAdapter::GeneralAdapter()
{
    scene = new CustomScene(GlobVal::sceneRect, nullptr);
    view = new CustomView(GlobVal::viewSize, scene, nullptr);
    view->show();

    boardSolver = new CustomBoard(GlobVal::boardSolver, 200, nullptr);
    scene->addItem(boardSolver);

    generalWidget = new GeneralWidget(nullptr);

    scene->addWidget(generalWidget);
    generalWidget->show();

    answerTextEdit = new AnswerTextEdit(nullptr);
    scene->addWidget(answerTextEdit);
    answerTextEdit->show();

    //коннект для инициализации доски значениями и ее отчистки от старый значений
    QObject::connect(generalWidget->getInputWidget(), &InputWidget::numberSubmitted,
                     boardSolver, &CustomBoard::initVecBlocks);

    //коннект для передачи текста
    QObject::connect(boardSolver, &CustomBoard::signalToSendPrimeNumber,
                     answerTextEdit, &AnswerTextEdit::appendOutput);

    //коннект для перемещения доски
    QObject::connect(generalWidget->getControllerWidget()->getBtnUp(), &QPushButton::clicked,
                     boardSolver, &CustomBoard::changePosUp);

    //коннект для возвращения позиции доски
    QObject::connect(generalWidget->getControllerWidget()->getBtnReturn(), &QPushButton::clicked,
                     boardSolver, &CustomBoard::changePosReturn);
}
