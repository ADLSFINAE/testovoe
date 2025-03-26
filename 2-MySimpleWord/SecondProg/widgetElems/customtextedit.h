#ifndef CUSTOMTEXTEDIT_H
#define CUSTOMTEXTEDIT_H

#include <QWidget>
#include <QTextEdit>

class CustomTextEdit : public QTextEdit{
    Q_OBJECT
public:
    CustomTextEdit() = default;
    CustomTextEdit(QWidget* parent);
signals:
    void sendToAlgorithm(QString text);
public slots:
    void slotSetBoldText(bool bold);
    void slotSetCursiveText(bool cursive);
};

#endif // CUSTOMTEXTEDIT_H
