#ifndef GENERALADAPTER_H
#define GENERALADAPTER_H

#include "guiElems/customscene.h"
#include "guiElems/customview.h"

#include "boardElems/customblock.h"
#include "boardElems/customboard.h"

#include "widgetElems/generalwidget.h"
#include "widgetElems/answertextedit.h"

#include "paramsNdefines.h"

class GeneralAdapter : public QObject
{
    Q_OBJECT
public:
    GeneralAdapter();

private:
    CustomScene* _scene{nullptr};

    CustomView* _view{nullptr};

    CustomBoard* _boardSolver{nullptr};

    GeneralWidget* _generalWidget{nullptr};

    AnswerTextEdit* _answerTextEdit{nullptr};

};

#endif // GENERALADAPTER_H
