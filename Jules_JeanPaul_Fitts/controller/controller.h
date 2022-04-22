#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model/model.h"
#include "view/view.h"
#include "settingscontroller.h"
#include "savecontroller.h"

#include <QObject>
#include <QApplication>
#include <QSettings>
#include <QRandomGenerator>
#include <QElapsedTimer>
#include <Windows.h>

class SaveController;
class View;

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
    void initGame();
    void finish();
    void nextCible();
    QElapsedTimer* timer;
    Model* model;
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
