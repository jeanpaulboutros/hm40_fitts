#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QMainWindow>

class Controller : public QMainWindow
{
    Q_OBJECT

public:
    Controller();
    ~Controller();
    void start();
    void updateAxisX();

    double getA();
    double getB();
    int getNbCible();
    int getMinSize();
    int getMaxSize();

    double getEcartType();
    double getErreurType();
    double getDiffMoy();
    double getItc95();

private:
    void initGame();
    void finish();
    void nextCible();

    void calculateResults();
    void calculateResultIDT();
    void calculateResult2DL();
    void applyConfig();

   /* FittsModel *fittsModel;
    ResultsModel *resultsModel;
    MainView *mainView;
    QElapsedTimer *timer;*/

private slots:
    void quit();
    void startSimulation();

    void aSpinChanged(double value);
    void bSpinChanged(double value);
    void nbCibleSpinChanged(int value);
    void minSizeSpinChanged(int value);
    void maxSizeSpinChanged(int value);

    void cibleClicked(int x, int y);

    void prevChart();
    void nextChart();

    void saveConfig();

    void restart();
};
#endif // CONTROLLER_H
