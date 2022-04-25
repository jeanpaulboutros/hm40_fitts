#ifndef SIDEMENU_H
#define SIDEMENU_H

#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QApplication>
#include <QStyle>
#include <QFont>
#include "controller/controller.h"
#include "model/settingsModel.h"
#include "view/view.h"

class Controller;
class View;
class SideMenu : public QFrame
{
    Q_OBJECT

public:

    QPushButton* getDataButton;
    QPushButton* analyseButton;
    QPushButton* settingsButton;
    QPushButton* helpButton;
    QPushButton* exitButton;

    QVBoxLayout* upperLayout;
    QVBoxLayout* bottomLayout;

    SideMenu(QWidget* parent);
    ~SideMenu();



private:

    void initStyle();

    void initGetDataButton();
    void initAnalyseButton();
    void initSettingsButton();
    void initHelpButton();
    void initExitButton();
    Controller* mainController;
    View* view;
};




#endif // SIDEMENU_H
