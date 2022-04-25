#ifndef TESTCONTROLLER_H
#define TESTCONTROLLER_H

#include <QObject>
#include <QApplication>
#include <QElapsedTimer>
#include "view/fittstest.h"
#include "model/testmodel.h"
#include "model/settingsModel.h"
#include "view/view.h"

class FittsTest;
class View;
class TestController : public QObject
{
    Q_OBJECT
public:
    TestController(FittsTest* fittsTest, TestModel* testModel);
    ~TestController();
    void initGame();
    void nextCible();
    void finish();

private:
    FittsTest* fittsTest;
    TestModel* testModel;
    SettingsModel* sm;
    QElapsedTimer *timer;
    View* mainView;

public slots:

    void cibleClicked(int x, int y);
    void startButtonClicked();
    void restartTest();
    /*void saveConfig();
    void backToMenu();
    void restartTest();*/

    friend FittsTest;
};

#endif // TESTCONTROLLER_H
