#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QPushButton>
#include <QBrush>
#include "paramsNglobFunctions.h"

class CustomButton : public QPushButton
{
    Q_OBJECT
public:
    CustomButton() = default;
    CustomButton(QString text, QWidget* parent);

    bool getIsActive() const{return _isActive;};

signals:
    void signalToChangeColor();
public slots:
    void changeColor();
    void changeIsActive();
private:
    QBrush _brush;
    bool _isActive = false;
};

#endif // CUSTOMBUTTON_H
