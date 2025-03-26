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
    void vivodddd();
};

#endif // CUSTOMTEXTEDIT_H
