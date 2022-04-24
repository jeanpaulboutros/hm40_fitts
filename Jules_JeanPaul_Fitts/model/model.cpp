#include "model.h"


Model::Model()
{
    this->settingsModel = new SettingsModel();
    this->saveModel = new SaveModel();

}


Model::~Model()
{

}
