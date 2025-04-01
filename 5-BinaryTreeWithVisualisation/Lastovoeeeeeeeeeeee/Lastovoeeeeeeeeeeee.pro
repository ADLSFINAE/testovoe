QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    generaladapter.cpp \
    main.cpp \
    resultWidget/resultwidget.cpp \
    treeLogic/treeNode/treenode.cpp \
    treeLogic/treeanalysator.cpp \
    treeVisual/treebuilder.cpp \
    treeVisual/treevisualiser.cpp

HEADERS += \
	generaladapter.h \
	resultWidget/resultwidget.h \
	treeLogic/treeNode/treenode.h \
	treeLogic/treeanalysator.h \
	treeVisual/treebuilder.h \
	treeVisual/treevisualiser.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
