QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller/controller.cpp \
    main.cpp \
    model/model.cpp \
    view/fittstest.cpp \
    view/graphicwidget.cpp \
    view/mainmenuview.cpp \
    view/view.cpp

HEADERS += \
    controller/controller.h \
    model/model.h \
    view/fittstest.h \
    view/graphicwidget.h \
    view/mainmenuview.h \
    view/view.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
