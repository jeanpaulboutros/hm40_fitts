#include "testmodel.h"

TestModel::TestModel()
{
    SettingsModel* sm = new SettingsModel();
    this->maxSize = sm->getMaxSize();
    this->minSize = sm->getMinSize();
    this->nbCible = sm->getNbCible();
}

