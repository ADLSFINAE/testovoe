#include "generaladapter.h"

GeneralAdapter::GeneralAdapter()
{
    genWgt = new GeneralWidget(nullptr);
    genWgt->show();

    panWgt = new PanelWidget(genWgt);
    panWgt->show();
}
