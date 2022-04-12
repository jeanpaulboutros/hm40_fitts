#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QFrame>
#include <QMainWindow>
#include <QHBoxLayout>

#include "sideMenu.h"
#include "graphScreen.h"
#include "saveMenu.h"
#include "view/settingsscreen.h"

#include "fittstest.h"
#include <QGuiApplication>
#include <QScreen>
#include <QStackedLayout>

class FittsTest;
class Controller;

class View : public QFrame
{
    Q_OBJECT

public:

    SideMenu* sideMenu;
    GraphScreen* graphscreen;
    SaveMenu* saveMenu;
    SettingsScreen* settingsScreen;

    View();
    ~View();
    View(Controller *mainController);
    void initWindows(Controller *mainController);


private:

    void initWindows();
    void displayTitle(QLayout *mainLayout);

    FittsTest *fittsTest;
    QStackedLayout *mainStack;

    friend Controller;

};

#endif // VIEW_H
