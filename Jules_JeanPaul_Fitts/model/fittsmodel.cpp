#include "fittsmodel.h"

FittsModel::FittsModel()
{

}
FittsModel::~FittsModel(){

}

int FittsModel::getMinSize() const
{
    return minSize;
}

void FittsModel::setMinSize(int newMinSize)
{
    if(newMinSize < this->maxSize)
    {
        minSize = newMinSize;
    }else{
        return;
    }
}



int FittsModel::getMaxSize() const
{
    return maxSize;
}

void FittsModel::setMaxSize(int newMaxSize)
{
    if(newMaxSize > this->minSize)
    {
        maxSize = newMaxSize;
    }else{
        return;
    }
}

double FittsModel::getA() const
{
    return a;
}

void FittsModel::setA(double newA)
{
    a = newA;
}

double FittsModel::getB() const
{
    return b;
}

void FittsModel::setB(double newB)
{
    b = newB;
}

