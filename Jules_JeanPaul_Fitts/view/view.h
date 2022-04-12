#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QFrame>
#include <QMainWindow>
#include <QHBoxLayout>

#include "sideMenu.h"
#include "graphScreen.h"
#include "saveMenu.h"
#include "settingsScreen.h"


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

private:

    void initWindows();

};

#endif // VIEW_H
