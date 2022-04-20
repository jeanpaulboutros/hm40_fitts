#include "settingsModel.h"

SettingsModel::SettingsModel()
{

}
SettingsModel::~SettingsModel(){

}

int SettingsModel::getMinSize() const
{
    return minSize;
}

void SettingsModel::setMinSize(int newMinSize)
{
    if(newMinSize < this->maxSize)
    {
        minSize = newMinSize;
    }else{
        return;
    }
}



int SettingsModel::getMaxSize() const
{
    return maxSize;
}

void SettingsModel::setMaxSize(int newMaxSize)
{
    if(newMaxSize > this->minSize)
    {
        maxSize = newMaxSize;
    }else{
        return;
    }
}

double SettingsModel::getA() const
{
    return a;
}

void SettingsModel::setA(double newA)
{
    a = newA;
}

double SettingsModel::getB() const
{
    return b;
}

void SettingsModel::setB(double newB)
{
    b = newB;
}

void SettingsModel::debugValue()
{
    qDebug("a = %f", this->a);
    qDebug("b = %f", this->b);
    qDebug("NbCible = %d", this->nbCible);
    qDebug("MinSize = %d", this->minSize);
    qDebug("MaxSize = %d", this->maxSize);

}

int SettingsModel::getNbCible() const
{
    return nbCible;
}

void SettingsModel::setNbCible(int newNbCible)
{
    if(newNbCible < 1 || newNbCible > 100)
    {
        return;
    }else{
        nbCible = newNbCible;
    }
}

