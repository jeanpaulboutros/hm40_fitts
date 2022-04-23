#include "view.h"

View::View() : QFrame(0)
{


}

View::View(Model* mainModel) : View(){

    this->mainModel = mainModel;
    initWindows();

    this->sideMenu = new SideMenu(this);
    this->settingsScreen = new SettingsScreen(0, this->mainModel->settingsModel);
    this->graphscreen = new GraphScreen(this);
    this->saveMenu = new SaveMenu(this);


    this->layout()->addWidget(this->sideMenu);
    //this->layout()->addWidget(this->settingsScreen);
    this->layout()->addWidget(this->graphscreen);
    this->layout()->addWidget(this->saveMenu);

}


View::~View()
{

}

void View::initWindows()
{
    this->setWindowTitle("Fitts");
    this->setLayout(new QHBoxLayout());
}


void View::loadStyleSheet(QApplication *app) {
    QFile styleFile(":/assets/stylesheet.qss");
    styleFile.open( QFile::ReadOnly );
    app->setStyleSheet( QString::fromLatin1( styleFile.readAll() ) );
    styleFile.close();
}



