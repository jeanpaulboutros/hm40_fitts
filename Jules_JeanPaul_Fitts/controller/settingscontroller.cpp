#include "settingscontroller.h"


SettingsController::SettingsController(SettingsScreen* settingsScreen, SettingsModel* settingsModel)
{
    this->settingsScreen = settingsScreen;
    this->settingsModel = settingsModel;
    addSettingsConnection();
}

SettingsController::~SettingsController()
{

}

void SettingsController::addSettingsConnection()
{
    connect(this->settingsScreen->nbTargetSlider, SIGNAL(valueChanged(int)), this, SLOT(changeNbOfTarget()));
    connect(this->settingsScreen->minSizeTargetSlider, SIGNAL(valueChanged(int)), this, SLOT(changeMinSizeTarget()));
    connect(this->settingsScreen->maxSizeTargetSlider, SIGNAL(valueChanged(int)), this, SLOT(changeMaxSizeTarget()));
}


void SettingsController::changeNbOfTarget()
{
    this->settingsModel->setNbCible(this->settingsScreen->nbTargetSlider->value());
    this->settingsModel->debugValue();

}

void SettingsController::changeMinSizeTarget()
{
    this->settingsModel->setMinSize(this->settingsScreen->minSizeTargetSlider->value());
    this->settingsScreen->renderMinSizeTargetScene();
    this->settingsModel->debugValue();
}

void SettingsController::changeMaxSizeTarget()
{
    this->settingsModel->setMaxSize(this->settingsScreen->maxSizeTargetSlider->value());
    this->settingsScreen->renderMaxSizeTargetScene();
    this->settingsModel->debugValue();
}
