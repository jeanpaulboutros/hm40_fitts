#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model/settingsModel.h"
#include "model/model.h"
#include "view/view.h"
#include "controller/settingscontroller.h"
#include "controller/testcontroller.h"
#include "controller/savecontroller.h"


#include <QObject>
#include <QApplication>
#include <QSettings>
#include <QRandomGenerator>
#include <QElapsedTimer>
#include <Windows.h>


class FittsTest;
class TestController;
class SettingsModel;
class View;
class SaveController;

class Controller : public QObject
{
    Q_OBJECT

public:
    Controller(Model* mainModel, View* mainView);
    ~Controller();
    void start();
    double getA();
    double getB();
    int getNbCible();

    SettingsController* settingsController;
    SaveController* saveController;


private:
    Model* model;
    View* mainView;
    TestController* testController;

public slots:
    void quit();
    void toTest();
    void toGraph();
    void toSettings();
    void toHelp();
    void restartTest();


};

#endif // CONTROLLER_H
