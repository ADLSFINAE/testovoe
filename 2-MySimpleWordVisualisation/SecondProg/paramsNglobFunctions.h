#ifndef PARAMSNGLOBFUNCTIONS_H
#define PARAMSNGLOBFUNCTIONS_H

#include <QString>
#include <QBrush>

namespace GlobVal{
inline QString hexColorToSimpleColor(Qt::GlobalColor color)
{
    switch(color) {
    case Qt::cyan:    return "#00FFFF";
    case Qt::black:  return "#000000";
    case Qt::white:   return "#FFFFFF";

    default:{return "#000000";}; // черный
    }
}

#define PANEL_WIDGET(widget) (widget->getPanelWidget())
#define TEXTEDIT_WIDGET(widget) (widget->getInputWidget())

};

#endif // PARAMSNGLOBFUNCTIONS_H
