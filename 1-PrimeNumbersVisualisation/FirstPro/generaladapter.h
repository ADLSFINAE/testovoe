#ifndef GENERALADAPTER_H
#define GENERALADAPTER_H

#include "guiElems/customscene.h"
#include "guiElems/customview.h"

#include "boardElems/customblock.h"
#include "boardElems/customboard.h"

#include "widgetElems/generalwidget.h"
#include "widgetElems/answertextedit.h"

#include "paramsNdefines.h"

class GeneralAdapter
{
public:
    GeneralAdapter();

private:
    CustomScene* scene{nullptr};
    CustomView* view{nullptr};

    CustomBoard* boardSolver{nullptr};

    GeneralWidget* generalWidget{nullptr};

    AnswerTextEdit* answerTextEdit{nullptr};
};

#endif // GENERALADAPTER_H
