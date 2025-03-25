#ifndef CONTROLLERWIDGET_H
#define CONTROLLERWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class ControllerWidget : public QWidget
{
    Q_OBJECT
public:
    ControllerWidget() = default;
    ControllerWidget(QWidget* parent);

    QPushButton* getBtnInstaResult() const{return btnInstaResult;};
private:
    QPushButton* btnInstaResult{nullptr};

    QVBoxLayout* layout{nullptr};
};

#endif // CONTROLLERWIDGET_H
