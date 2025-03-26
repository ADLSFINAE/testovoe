#include "customtextedit.h"

CustomTextEdit::CustomTextEdit(QWidget *parent)
{
    this->setParent(parent);
    QObject::connect(this, &CustomTextEdit::textChanged, this, &CustomTextEdit::vivodddd);
}

void CustomTextEdit::vivodddd()
{
    qDebug()<<this->toPlainText();
}
