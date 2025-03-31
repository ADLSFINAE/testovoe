#include "generaladapter.h"

GeneralAdapter::GeneralAdapter()
{
    _scene = new CustomScene(GlobVal::sceneRect, nullptr);

    _view = new CustomView(GlobVal::viewSize, _scene, nullptr);

    _view->show();

    _boardSolver = new CustomBoard(GlobVal::boardSolver, 200, nullptr);

    _scene->addItem(_boardSolver);

    _generalWidget = new GeneralWidget(nullptr);

    _scene->addWidget(_generalWidget);

    _answerTextEdit = new AnswerTextEdit(nullptr);

    _scene->addWidget(_answerTextEdit);

    //коннект для инициализации доски значениями и ее отчистки от старый значений
    QObject::connect(_generalWidget->getInputWidget(), &InputWidget::numberSubmitted,
                     _boardSolver, &CustomBoard::initVecBlocks);

    //коннект для передачи текста
    QObject::connect(_boardSolver, &CustomBoard::signalToSendPrimeNumber,
                     _answerTextEdit, &AnswerTextEdit::appendOutput);

    //коннект для перемещения доски
    QObject::connect(_generalWidget->getControllerWidget()->getBtnUp(), &QPushButton::clicked,
                     _boardSolver, &CustomBoard::changePosUp);

    //коннект для возвращения позиции доски
    QObject::connect(_generalWidget->getControllerWidget()->getBtnReturn(), &QPushButton::clicked,
                     _boardSolver, &CustomBoard::changePosReturn);

    //коннект для выбора режима с таймером и без
    QObject::connect(_generalWidget->getControllerWidget()->getBtnOnTimer(), &QPushButton::clicked,
                     _boardSolver, &CustomBoard::changeIsTimerOn);
}
