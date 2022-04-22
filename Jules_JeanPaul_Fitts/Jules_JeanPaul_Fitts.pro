QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += gui

CONFIG += c++11


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller/savecontroller.cpp \
    controller/settingscontroller.cpp \
    main.cpp \
    controller/controller.cpp \
    model/model.cpp \
    model/savemodel.cpp \
    model/settingsModel.cpp \
    view/GraphicWidget.cpp \
    view/fittstest.cpp \
    view/graphScreen.cpp \
    view/saveMenu.cpp \
    view/settingsScreen.cpp \
    view/sideMenu.cpp \
    view/view.cpp

HEADERS += \
    controller/controller.h \
    controller/savecontroller.h \
    controller/settingscontroller.h \
    model/model.h \
    model/savemodel.h \
    model/settingsModel.h \
    view/GraphicWidget.h \
    view/fittstest.h \
    view/graphScreen.h \
    view/saveMenu.h \
    view/settingsScreen.h \
    view/view.h \
    view/sideMenu.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    assets/stylesheet.qss


RESOURCES += \
    assets/right-arrow.png \
    assets/left-arrow.png \
    assets/equation2.png \
    assets/save.png \
    assets/play.png \
    assets/stylesheet.qss
