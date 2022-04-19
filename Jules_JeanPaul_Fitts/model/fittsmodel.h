#ifndef FITTSMODEL_H
#define FITTSMODEL_H

#include <QPoint>
#include <QList>

class Controller;

class FittsModel
{
public:
    FittsModel();
    ~FittsModel();

    int getMinSize() const;
    void setMinSize(int newMinSize);

    int getMaxSize() const;
    void setMaxSize(int newMaxSize);

    double getA() const;
    void setA(double newA);

    double getB() const;
    void setB(double newB);

private:
    int cibleLeft = 0;
    int nbCible = 10;
    int minSize = 30;
    int maxSize = 150;

    double a = 0.20;
    double b = 0.10;

    QList<int> cercleSize;
    QList<QPoint> cercleCenter;


    friend Controller;
};

#endif // FITTSMODEL_H
