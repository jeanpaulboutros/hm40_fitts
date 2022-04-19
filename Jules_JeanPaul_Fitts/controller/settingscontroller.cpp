#include "settingscontroller.h"

SettingsController::SettingsController(SettingsScreen* settingsScreen)
{
    this->settingsScreen = settingsScreen;
    addSettingsConnection();
}

SettingsController::~SettingsController()
{

}

void SettingsController::addSettingsConnection()
{
    connect(this->settingsScreen->nbTargetSlider, SIGNAL(valueChanged(int)), this, SLOT(changeNbOfTarget()));
}

void SettingsController::changeNbOfTarget()
{
    qDebug("Hello World");
}
