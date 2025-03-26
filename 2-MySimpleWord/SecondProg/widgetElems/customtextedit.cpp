#include "customtextedit.h"

CustomTextEdit::CustomTextEdit(QWidget *parent)
{
    this->setParent(parent);
}

void CustomTextEdit::slotSetBoldText(bool bold)
{
    if (bold) {
        this->setFontWeight(QFont::Bold);
    } else {
        this->setFontWeight(QFont::Normal);
    }
}

void CustomTextEdit::slotSetCursiveText(bool cursive)
{
    if (cursive) {
        this->setFontItalic(true);
    } else {
        this->setFontItalic(false);
    }
}

