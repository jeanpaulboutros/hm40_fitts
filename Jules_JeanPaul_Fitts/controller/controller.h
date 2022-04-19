#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model/fittsmodel.h"
#include "view/view.h"
#include "controller/settingscontroller.h"

#include <QObject>
#include <QApplication>
#include <QSettings>
#include <QRandomGenerator>
#include <QElapsedTimer>
#include <Windows.h>


class FittsTest;
class FittsModel;
class View;

class Controller : public QObject
{
    Q_OBJECT

public:
    Controller(FittsModel* mainModel, View* mainView);
    ~Controller();
    void start();
    double getA();
    double getB();
    int getNbCible();

    SettingsController* settingsController;

private:
    void initGame();
    void finish();
    void nextCible();
    QElapsedTimer* timer;
    FittsModel* fittsModel;
    View* mainView;

private slots:
    void quit();
    void startSimulation();
    void cibleClicked(int x, int y);
    void saveConfig();
    void backToMenu();
    void restartTest();

};

#endif // CONTROLLER_H
