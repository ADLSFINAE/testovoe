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

    QPushButton* getBtnUp() const{return btnUp;};
    QPushButton* getBtnReturn() const{return btnReturn;};
private:
    QPushButton* btnUp{nullptr};
    QPushButton* btnReturn{nullptr};

    QVBoxLayout* layout{nullptr};
};

#endif // CONTROLLERWIDGET_H
