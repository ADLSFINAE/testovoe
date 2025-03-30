#ifndef GENERALWIDGET_H
#define GENERALWIDGET_H

#include <QWidget>
#include <bitset>
#include "widgetElems/infowidget.h"
#include "widgetElems/inputwidget.h"

class GeneralWidget : public QWidget
{
    Q_OBJECT
public:
    GeneralWidget() = default;

    GeneralWidget(QWidget* parent = nullptr);

    QFrame* createStyledFrame(QWidget *content, bool stretchContent);

    InfoWidget* getInfoWidgetVals() const{return infoWidgetVals;}

    InfoWidget* getInfoWidgetMin() const{return infoWidgetMin;}

    InfoWidget* getInfoWidgetMax() const{return infoWidgetMax;}

    InputWidget* getInputWidget() const{return inputWidget;}

    QString bitsetToQString(const std::bitset<32>& bits, bool withSpaces = true, bool reverse = false)
    {
        QString result = QString::fromStdString(bits.to_string());

        if (reverse) {
            std::reverse(result.begin(), result.end());
        }

        if (withSpaces && 32 > 4) {
            for (int i = result.length() - 4; i > 0; i -= 4) {
                result.insert(i, ' ');
            }
        }

        return result;
    }

public slots:
    void slotSetNumberLabelValues(quint32 number);

    void slotSetNumberLabelMin(quint32 number);

    void slotSetNumberLabelMax(quint32 number);

private:
    InfoWidget* infoWidgetVals{nullptr};
    InfoWidget* infoWidgetMin{nullptr};
    InfoWidget* infoWidgetMax{nullptr};

    InputWidget* inputWidget{nullptr};

    quint32 currentIntegerForValues;

    quint32 currentIntegerForMin;

    quint32 currentIntergerForMax;
};

#endif // GENERALWIDGET_H
