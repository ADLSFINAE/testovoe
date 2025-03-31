#ifndef GENERALWIDGET_H
#define GENERALWIDGET_H

#include <QWidget>
#include <bitset>
#include <QVBoxLayout>
#include <QFrame>
#include <QFont>
#include <QSpacerItem>

#include "widgetElems/infowidget.h"
#include "widgetElems/inputwidget.h"

class GeneralWidget : public QWidget
{
    Q_OBJECT
public:
    GeneralWidget() = default;

    GeneralWidget(QWidget* parent = nullptr);

    QFrame* createStyledFrame(QWidget *content, bool stretchContent);

    InfoWidget* getInfoWidgetVals() const;

    InfoWidget* getInfoWidgetMin() const;

    InfoWidget* getInfoWidgetMax() const;

    InputWidget* getInputWidget() const;

    QString bitsetToQString(const std::bitset<32>& bits, bool withSpaces = true, bool reverse = false);

public slots:
    void slotSetNumberLabelValues(quint32 number);

    void slotSetNumberLabelMin(quint32 number);

    void slotSetNumberLabelMax(quint32 number);

private:
    InfoWidget* _infoWidgetVals{nullptr};

    InfoWidget* _infoWidgetMin{nullptr};

    InfoWidget* _infoWidgetMax{nullptr};

    InputWidget* _inputWidget{nullptr};

    QFont _labelFont;

    QFrame* _valuesFrame{nullptr};
    QFrame* _minFrame{nullptr};
    QFrame* _maxFrame{nullptr};
    QFrame* _inputFrame{nullptr};

    QVBoxLayout* _mainLayout{nullptr};

    quint32 _currentIntegerForValues;

    quint32 _currentIntegerForMin;

    quint32 _currentIntergerForMax;
};

#endif // GENERALWIDGET_H
