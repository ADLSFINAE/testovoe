#include "generalwidget.h"
#include <QVBoxLayout>
#include <QFrame>
#include <QFont>
#include <QSpacerItem>

GeneralWidget::GeneralWidget(QWidget *parent)
    : QWidget(parent)
{
    infoWidgetVals = new InfoWidget("Values:", this);
    infoWidgetMin = new InfoWidget("Min Value:", this);
    infoWidgetMax = new InfoWidget("Max Value:", this);
    inputWidget = new InputWidget(this);

    QFont labelFont("Arial", 10, QFont::Bold);
    infoWidgetVals->setFont(labelFont);
    infoWidgetMin->setFont(labelFont);
    infoWidgetMax->setFont(labelFont);

    QFrame* valuesFrame = createStyledFrame(infoWidgetVals, true);
    QFrame* minFrame = createStyledFrame(infoWidgetMin, true);
    QFrame* maxFrame = createStyledFrame(infoWidgetMax, true);
    QFrame* inputFrame = createStyledFrame(inputWidget, false);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(15, 15, 15, 15);
    mainLayout->setSpacing(15);

    mainLayout->addWidget(valuesFrame, 3);
    mainLayout->addWidget(minFrame, 1);
    mainLayout->addWidget(maxFrame, 1);
    mainLayout->addWidget(inputFrame, 1);

    mainLayout->addStretch(1);

    setStyleSheet(R"(
        QFrame {
            background-color: #f5f5f5;
            border-radius: 8px;
            border: 1px solid #ddd;
        }
        QLabel {
            color: #333;
            padding: 5px;
        }
    )");

    showMaximized();
}

QFrame* GeneralWidget::createStyledFrame(QWidget *content, bool stretchContent)
{
    QFrame *frame = new QFrame(this);
    frame->setFrameShape(QFrame::StyledPanel);
    frame->setFrameShadow(QFrame::Raised);

    QVBoxLayout *frameLayout = new QVBoxLayout(frame);
    frameLayout->setContentsMargins(10, 10, 10, 10);
    frameLayout->addWidget(content);

    if (stretchContent) {
        frameLayout->addStretch();
        content->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    } else {
        content->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    }

    return frame;
}

void GeneralWidget::slotSetNumberLabelValues(quint32 number)
{
    this->currentIntegerForValues = number;
    if(number <= 4294967295){
        infoWidgetVals->setIntegerValueLabel(QString::number(currentIntegerForValues));

        infoWidgetVals->setHexValueLabel(bitsetToQString(std::bitset<32>(currentIntegerForValues)));
    }
    else{
        infoWidgetVals->setIntegerValueLabel(QString("IS OUT OF RANGE"));

        infoWidgetVals->setHexValueLabel(bitsetToQString(std::bitset<32>(0)));
    }

}

void GeneralWidget::slotSetNumberLabelMin(quint32 number)
{
    this->currentIntegerForMin = number;
    if(number <= 4294967295){
        infoWidgetMin->setIntegerValueLabel(QString::number(currentIntegerForMin));

        infoWidgetMin->setHexValueLabel(bitsetToQString(std::bitset<32>(currentIntegerForMin)));
    }
    else{
        infoWidgetMin->setIntegerValueLabel(QString("IS OUT OF RANGE"));

        infoWidgetMin->setHexValueLabel(bitsetToQString(std::bitset<32>(0)));
    }

}

void GeneralWidget::slotSetNumberLabelMax(quint32 number)
{
    this->currentIntergerForMax = number;
    qDebug()<<number;
    if(number <= 4294967295){
        infoWidgetMax->setIntegerValueLabel(QString::number(currentIntergerForMax));

        infoWidgetMax->setHexValueLabel(bitsetToQString(std::bitset<32>(currentIntergerForMax)));
    }
    else{
        infoWidgetMax->setIntegerValueLabel(QString("IS OUT OF RANGE"));

        infoWidgetMax->setHexValueLabel(bitsetToQString(std::bitset<32>(0)));
    }
}

