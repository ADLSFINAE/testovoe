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
    QPushButton* btnUp{nullptr};

    QPushButton* btnReturn{nullptr};

    QPushButton* btnOnTimer{nullptr};

    bool isTimerOn = false;

    QVBoxLayout* layout{nullptr};

};

#endif // CONTROLLERWIDGET_H
