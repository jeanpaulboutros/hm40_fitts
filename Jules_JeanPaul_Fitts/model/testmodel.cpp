#include "testmodel.h"

TestModel::TestModel()
{
    this->sm = new SettingsModel();
    this->maxSize = sm->getMaxSize();
    this->minSize = sm->getMinSize();
    this->nbCible = sm->getNbCible();
}

void TestModel::calculateResults(){

}
