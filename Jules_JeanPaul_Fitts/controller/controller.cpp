#include "controller/controller.h"

Controller::Controller(Model* mainModel, View* mainView)
{
    this->model = mainModel;
    this->mainView = mainView;
    this->settingsController = new SettingsController(this->mainView->settingsScreen, this->model->settingsModel);
    this->saveController = new SaveController(this->model->saveModel, this->mainView->saveMenu);

    connect(mainView->sideMenu->getDataButton, SIGNAL(clicked()),this,SLOT(toTest()));
    connect(mainView->sideMenu->settingsButton, SIGNAL(clicked()),this,SLOT(toSettings()));
    connect(mainView->sideMenu->analyseButton,SIGNAL(clicked()),this,SLOT(toGraph()));
    connect(mainView->sideMenu->exitButton,SIGNAL(clicked()),this,SLOT(quit()));
    connect(mainView->sideMenu->helpButton,SIGNAL(clicked()),this,SLOT(toHelp()));

}

Controller::~Controller()
{
}

void Controller::start() {
    this->mainView->show();
    this->mainView->fittsTest->resizeScene();

}

void Controller::quit() {
    QMessageBox msgBox;
    msgBox.setText("<strong>Are you sure you want to exit? </strong>");
    msgBox.setInformativeText("Sad to see you leave :(");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();
    switch(ret){
        case QMessageBox::Yes :
        QApplication::exit();
        break;
        case QMessageBox::No :
        msgBox.close();
        break;
        default :
        msgBox.close();
        break;
    }
}

double Controller::getA(){
    return this->model->settingsModel->a;
}

double Controller::getB(){
    return this->model->settingsModel->b;
}

int Controller::getNbCible(){
    return this->model->settingsModel->nbCible;
}

void Controller::restartTest(){
    this->model->settingsModel->cercleSize.clear();
    this->model->settingsModel->cercleCenter.clear();
    this->mainView->mainStack->setCurrentIndex(0);
    //this->startSimulation();
}

void Controller::toTest(){
    this->mainView->mainStack->setCurrentIndex(0);
}
void Controller::toGraph(){
    this->mainView->mainStack->setCurrentIndex(2);
}
void Controller::toSettings(){
    this->mainView->mainStack->setCurrentIndex(1);
}
void Controller::toHelp(){
    this->mainView->mainStack->setCurrentIndex(3);
}

