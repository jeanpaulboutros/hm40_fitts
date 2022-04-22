#include "savecontroller.h"


SaveController::SaveController(SaveModel* model, SaveMenu* saveScreen)
{
    this->saveModel = model;
    this->saveScreen = saveScreen;
    this->saveModel->test();
    this->saveScreen->populate(this->saveModel->loadFile());
    connect(this->saveScreen->openSaveMenuButton, SIGNAL(clicked()), this, SLOT(openMenu()));

};



void SaveController::openMenu() {
    this->saveScreen->handleOpenSaveButton();

}
