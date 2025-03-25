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

    QPushButton* getBtnStart() const{return btnStart;};
    QPushButton* getBtnStop() const{return btnStop;};
    QPushButton* getBtnInstaResult() const{return btnInstaResult;};
private:
    QPushButton* btnStart{nullptr};
    QPushButton* btnStop{nullptr};
    QPushButton* btnInstaResult{nullptr};

    QVBoxLayout* layout{nullptr};
};

#endif // CONTROLLERWIDGET_H
