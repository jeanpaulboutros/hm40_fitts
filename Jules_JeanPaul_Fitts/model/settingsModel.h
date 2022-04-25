    #ifndef SETTINGSMODEL_H
#define SETTINGSMODEL_H

#include <QPoint>
#include <QList>

class Controller;

class SettingsModel
{
public:
    SettingsModel();
    ~SettingsModel();

    int getMinSize() const;
    void setMinSize(int newMinSize);

    int getMaxSize() const;
    void setMaxSize(int newMaxSize);

    double getA() const;
    void setA(double newA);

    double getB() const;
    void setB(double newB);

    void debugValue();

    int getNbCible() const;
    void setNbCible(int newNbCible);

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

#endif // SETTINGSMODEL_H
