#ifndef SAVECONTROLLER_H
#define SAVECONTROLLER_H

#include "view/view.h"
#include "model/savemodel.h"


class SaveController
{

private:
    SaveModel* saveModel;

public:
    SaveController(SaveModel* model);


};

#endif // SAVECONTROLLER_H
