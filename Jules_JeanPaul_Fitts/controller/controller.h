#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include"View/jpview.h"
#include "Model/fittsmodel.h"


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
    Controller();
    ~Controller();
    void start();
    double getA();
    double getB();
    int getNbCible();
private:
    void initGame();
    void finish();
    void nextCible();
    QElapsedTimer *timer;
    FittsTest *fittsTest;
    FittsModel *fittsModel;
    View *mainView;

private slots:
    void quit();
    void startSimulation();
    void cibleClicked(int x, int y);
    void saveConfig();
    void backToMenu();
    void restartTest();

};

#endif // MAINCONTROLLER_H
