#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QFrame>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QGuiApplication>
#include <QScreen>
#include <QStackedLayout>
#include <QPushButton>


#include "sideMenu.h"
#include "graphScreen.h"
#include "saveMenu.h"
#include "settingsScreen.h"
#include "fittstest.h"
#include "model/settingsModel.h"
#include "model/model.h"
#include "model/testmodel.h"
#include "view/help.h"

class Controller;
class TestModel;
class FittsTest;
class SideMenu;

class View : public QFrame
{
    Q_OBJECT

public:

    SideMenu* sideMenu;
    GraphScreen* graphscreen;
    SaveMenu* saveMenu;
    SettingsScreen* settingsScreen;
    QStackedLayout* mainStack;

    View();
    ~View();
    View(Model* mainModel);
    void loadStyleSheet(QApplication *app);


private:

    Model* mainModel;
    TestModel* testModel;
    FittsTest* fittsTest;
    Help* help;
    QVBoxLayout* objectsOnPage;
    Controller* mainController;

    void initWindows();



    friend Controller;

};

#endif // VIEW_H
