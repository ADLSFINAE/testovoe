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

    QPushButton* getBtnUp() const;

    QPushButton* getBtnReturn() const;

    QPushButton* getBtnOnTimer() const;

private slots:
    void slotChangeColorBtnOnTimer();

private:
    QPushButton* _btnUp{nullptr};

    QPushButton* _btnReturn{nullptr};

    QPushButton* _btnOnTimer{nullptr};

    bool _isTimerOn = false;

    QVBoxLayout* _layout{nullptr};

};

#endif // CONTROLLERWIDGET_H
