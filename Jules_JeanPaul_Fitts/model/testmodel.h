#ifndef TESTMODEL_H
#define TESTMODEL_H

#include <QList>
#include <QPoint>
#include "controller/testcontroller.h"
#include "view/fittstest.h"
#include "model/settingsModel.h"

class TestController;
class FittsTest;
class TestModel
{
public:
    TestModel();
    void calculateResults();
    /*QList<QPoint> getCercleCenter();
    QList<QPoint> getClickPoints();
    QList<int> getCercleSize();
    QList<qint64> getTimes();*/

    QList<QPoint> clickPoints;
    QList<QPoint> cercleCenter;
    QList<int> cercleSize;
    QList<qint64> times;

    FittsTest* fittsTest;
    SettingsModel* sm ;


    float ratio = 1;
    float failedClicks = 0;
    float clicks = 0;
    int cibleLeft = 0;
    int nbCible;
    int minSize;
    int maxSize;

    friend TestController;
    friend FittsTest;
};

#endif // TESTMODEL_H
