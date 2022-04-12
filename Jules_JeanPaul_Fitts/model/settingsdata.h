#ifndef SETTINGSDATA_H
#define SETTINGSDATA_H

#include <QDebug>


class SettingsData
{

public:

    SettingsData();
    SettingsData& operator=(const SettingsData& s);
    ~SettingsData();


    void debugData();


    float getA() const;
    void setA(float newA);

    float getB() const;
    void setB(float newB);

    int getTargetMinSize() const;
    void setTargetMinSize(int newTargetMinSize);

    int getTargetMaxSize() const;
    void setTargetMaxSize(int newTargetMaxSize);

    int getTargetNumber() const;
    void setTargetNumber(int newTargetNumber);

private:

    float a;
    float b;
    int targetMinSize;
    int targetMaxSize;
    int targetNumber;

};

#endif // SETTINGSDATA_H
