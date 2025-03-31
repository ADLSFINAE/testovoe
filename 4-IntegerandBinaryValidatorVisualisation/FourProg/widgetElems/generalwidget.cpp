#include "generalwidget.h"

GeneralWidget::GeneralWidget(QWidget *parent)
    : QWidget(parent)
{
    _infoWidgetVals = new InfoWidget("Values:", this);

    _infoWidgetMin = new InfoWidget("Min Value:", this);

    _infoWidgetMax = new InfoWidget("Max Value:", this);

    _inputWidget = new InputWidget(this);

    _labelFont = QFont("Arial", 10, QFont::Bold);

    _infoWidgetVals->setFont(_labelFont);

    _infoWidgetMin->setFont(_labelFont);

    _infoWidgetMax->setFont(_labelFont);

    _valuesFrame = createStyledFrame(_infoWidgetVals, true);

    _minFrame = createStyledFrame(_infoWidgetMin, true);

    _maxFrame = createStyledFrame(_infoWidgetMax, true);

    _inputFrame = createStyledFrame(_inputWidget, false);

    _mainLayout = new QVBoxLayout(this);

    _mainLayout->setContentsMargins(15, 15, 15, 15);

    _mainLayout->setSpacing(15);

    _mainLayout->addWidget(_valuesFrame, 3);

    _mainLayout->addWidget(_minFrame, 2);

    _mainLayout->addWidget(_maxFrame, 2);

    _mainLayout->addWidget(_inputFrame, 3);

    _mainLayout->addStretch(1);

    this->setStyleSheet(R"(
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

    this->showMaximized();
}

QFrame* GeneralWidget::createStyledFrame(QWidget *content, bool stretchContent)
{
    QFrame *frame = new QFrame(this);

    frame->setFrameShape(QFrame::StyledPanel);

    frame->setFrameShadow(QFrame::Raised);

    QVBoxLayout *frameLayout = new QVBoxLayout(frame);

    frameLayout->setContentsMargins(10, 10, 10, 10);

    frameLayout->addWidget(content);

    if(stretchContent){
        frameLayout->addStretch();
        content->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }

    else{
        content->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    }

    return frame;
}

InfoWidget *GeneralWidget::getInfoWidgetVals() const{
    return _infoWidgetVals;
}

InfoWidget *GeneralWidget::getInfoWidgetMin() const{
    return _infoWidgetMin;
}

InfoWidget *GeneralWidget::getInfoWidgetMax() const{
    return _infoWidgetMax;
}

InputWidget *GeneralWidget::getInputWidget() const{
    return _inputWidget;
}

QString GeneralWidget::bitsetToQString(const std::bitset<32> &bits, bool withSpaces, bool reverse)
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

void GeneralWidget::slotSetNumberLabelValues(quint32 number)
{
    this->_currentIntegerForValues = number;

    if(number <= static_cast<quint32>(4294967295)){
        _infoWidgetVals->setIntegerValueLabel(QString::number(_currentIntegerForValues));

        _infoWidgetVals->setBinaryValueLabel(bitsetToQString(std::bitset<32>(_currentIntegerForValues)));

    }
    else{
        _infoWidgetVals->setIntegerValueLabel(QString("IS OUT OF RANGE"));

        _infoWidgetVals->setBinaryValueLabel(bitsetToQString(std::bitset<32>(0)));

    }

}

void GeneralWidget::slotSetNumberLabelMin(quint32 number)
{
    this->_currentIntegerForMin = number;

    if(number <= static_cast<quint32>(4294967295)){
        _infoWidgetMin->setIntegerValueLabel(QString::number(_currentIntegerForMin));

        _infoWidgetMin->setBinaryValueLabel(bitsetToQString(std::bitset<32>(_currentIntegerForMin)));

    }
    else{
        _infoWidgetMin->setIntegerValueLabel(QString("IS OUT OF RANGE"));

        _infoWidgetMin->setBinaryValueLabel(bitsetToQString(std::bitset<32>(0)));

    }

}

void GeneralWidget::slotSetNumberLabelMax(quint32 number)
{
    this->_currentIntergerForMax = number;

    if(number <= static_cast<quint32>(4294967295)){
        _infoWidgetMax->setIntegerValueLabel(QString::number(_currentIntergerForMax));

        _infoWidgetMax->setBinaryValueLabel(bitsetToQString(std::bitset<32>(_currentIntergerForMax)));

    }
    else{
        _infoWidgetMax->setIntegerValueLabel(QString("IS OUT OF RANGE"));

        _infoWidgetMax->setBinaryValueLabel(bitsetToQString(std::bitset<32>(0)));

    }

}

