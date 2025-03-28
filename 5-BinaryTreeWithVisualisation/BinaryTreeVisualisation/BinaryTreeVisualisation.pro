QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    generaladapter.cpp \
    guiElems/TreeVisualisation/treevisualcontroller.cpp \
    guiElems/customEllipse/customellipse.cpp \
    guiElems/customscene.cpp \
    guiElems/customview.cpp \
    logicElems/treealgorithm.cpp \
    main.cpp

HEADERS += \
	generaladapter.h \
	guiElems/TreeVisualisation/treevisualcontroller.h \
	guiElems/customEllipse/customellipse.h \
	guiElems/customscene.h \
	guiElems/customview.h \
	logicElems/treealgorithm.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
