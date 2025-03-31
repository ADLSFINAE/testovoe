QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    generaladapter.cpp \
    guiElems/customRectangle/customrectangle.cpp \
    guiElems/customRectangle/itemscontroller.cpp \
    guiElems/customscene.cpp \
    guiElems/customview.cpp \
    logicElems/list.cpp \
    logicElems/listalgorithm.cpp \
    main.cpp \
    widgetWithInputNumber/inputwidget.cpp

HEADERS += \
	customscene.h \
	customview.h \
	generaladapter.h \
	guiElems/customRectangle/customrectangle.h \
	guiElems/customRectangle/itemscontroller.h \
	guiElems/customscene.h \
	guiElems/customview.h \
	logicElems/list.h \
	logicElems/listalgorithm.h \
	widgetWithInputNumber/inputwidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
	res.qrc
