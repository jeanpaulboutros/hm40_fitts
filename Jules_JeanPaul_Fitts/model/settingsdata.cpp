#include "settingsdata.h"

SettingsData::SettingsData()
{
    this->a = 0.1f;
    this->b = 0.1f;
    this->targetMinSize = 10;
    this->targetMaxSize = 150;
    this->targetNumber = 10;
    debugData();
}

SettingsData& SettingsData::operator=(const SettingsData& s)
{
    this->a = s.getA();
    this->b = s.getB();
    this->targetMinSize = s.getTargetMinSize();
    this->targetMaxSize = s.getTargetMaxSize();
    this->targetNumber = s.getTargetNumber();

    return *this;
}

SettingsData::~SettingsData()
{

}


void SettingsData::debugData()
{
    qDebug("A = %f", this->a);
    qDebug("B = %f", this->b);
    qDebug("targetMinSize = %d", this->targetMinSize);
    qDebug("targetMaxSize = %d", this->targetMaxSize);
    qDebug("targetNumber = %d", this->targetNumber);

}


float SettingsData::getA() const
{
    return a;
}

void SettingsData::setA(float newA)
{
    a = newA;
}

float SettingsData::getB() const
{
    return b;
}

void SettingsData::setB(float newB)
{
    b = newB;
}

int SettingsData::getTargetMinSize() const
{
    return targetMinSize;
}

void SettingsData::setTargetMinSize(int newTargetMinSize)
{
    if(newTargetMinSize < this->targetMaxSize)
    {
        targetMinSize = newTargetMinSize;
    }else{
        return;
    }
}

int SettingsData::getTargetMaxSize() const
{
    return targetMaxSize;
}

void SettingsData::setTargetMaxSize(int newTargetMaxSize)
{
    if(newTargetMaxSize > this->targetMinSize)
    {
        targetMaxSize = newTargetMaxSize;
    }else{
        return;
    }
}

int SettingsData::getTargetNumber() const
{
    return targetNumber;
}

void SettingsData::setTargetNumber(int newTargetNumber)
{
    targetNumber = newTargetNumber;
}
