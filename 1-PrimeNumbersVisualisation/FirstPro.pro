QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    boardElems/customblock.cpp \
    boardElems/customboard.cpp \
    generaladapter.cpp \
    guiElems/customscene.cpp \
    guiElems/customview.cpp \
    main.cpp \
    widgetElems/answertextedit.cpp \
    widgetElems/controllerwidget.cpp \
    widgetElems/generalwidget.cpp \
    widgetElems/inputwidget.cpp

HEADERS += \
	boardElems/customblock.h \
	boardElems/customboard.h \
	generaladapter.h \
	guiElems/customscene.h \
	guiElems/customview.h \
	paramsNdefines.h \
	widgetElems/answertextedit.h \
	widgetElems/controllerwidget.h \
	widgetElems/generalwidget.h \
	widgetElems/inputwidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
