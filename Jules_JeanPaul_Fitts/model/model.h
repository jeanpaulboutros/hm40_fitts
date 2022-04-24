#ifndef MODEL_H
#define MODEL_H


#include "savemodel.h"
#include "settingsModel.h"

class Model
{

public:

    SaveModel* saveModel;
    SettingsModel* settingsModel;
    Model();
    ~Model();

};

#endif // MODEL_H
