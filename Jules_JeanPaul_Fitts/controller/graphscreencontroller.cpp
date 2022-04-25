#include "graphscreencontroller.h"


GraphScreenController::GraphScreenController(GraphScreen *graphScreen, SettingsModel *settingsModel)
{
    this->graphScreen = graphScreen;
    this->settingsModel = settingsModel;

    addConnection();
}

GraphScreenController::~GraphScreenController()
{

}

void GraphScreenController::addConnection()
{
    connect(this->graphScreen->aValueSlider, SIGNAL(valueChanged(int)), this, SLOT(changeAValue()));
    connect(this->graphScreen->bValueSlider, SIGNAL(valueChanged(int)), this, SLOT(changeBValue()));
    connect(this->graphScreen->leftArrow, SIGNAL(clicked()), this, SLOT(switchChartView()));
    connect(this->graphScreen->rightArrow, SIGNAL(clicked()), this, SLOT(switchChartView()));
}

void GraphScreenController::changeAValue()
{
    this->settingsModel->setA(this->graphScreen->aValueSlider->value()*0.1);
    this->graphScreen->printAValue();
}

void GraphScreenController::changeBValue()
{
    this->settingsModel->setB(this->graphScreen->bValueSlider->value()*0.1);
    this->graphScreen->printBValue();
}

void GraphScreenController::switchChartView()
{
    this->graphScreen->changeChartView();
}
