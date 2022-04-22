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
#include "model/model.h"

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

    View();
    ~View();
    View(Model* mainModel);
//    void initWindows(Controller *mainController);
    void loadStyleSheet(QApplication *app);


private:

    Model* mainModel;
    FittsTest* fittsTest;
    QStackedLayout* mainStack;

    void initWindows();
//    void displayTitle(QLayout *mainLayout);



    friend Controller;

};

#endif // VIEW_H
