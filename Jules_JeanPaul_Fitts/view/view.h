#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QFrame>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QGuiApplication>
#include <QScreen>
#include <QStackedLayout>


#include "sideMenu.h"
#include "graphScreen.h"
#include "saveMenu.h"
#include "settingsScreen.h"
#include "fittstest.h"
#include "model/fittsmodel.h"

class Controller;
class FittsTest;

class View : public QFrame
{
    Q_OBJECT

public:

    SideMenu* sideMenu;
    GraphScreen* graphscreen;
    SaveMenu* saveMenu;
    SettingsScreen* settingsScreen;
    Controller* controller;

    View();
    ~View();
    View(FittsModel* mainModel);
    void initWindows(Controller *mainController);


private:

    void initWindows();
    void displayTitle(QLayout *mainLayout);

    FittsModel* mainModel;
    FittsTest* fittsTest;
    QStackedLayout *mainStack;

    friend Controller;

};

#endif // VIEW_H
