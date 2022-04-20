#include "view.h"

View::View() : QFrame(0)
{


}

View::View(SettingsModel* mainModel) : View(){

    this->mainModel = mainModel;
    initWindows();

    this->sideMenu = new SideMenu(this);
    this->settingsScreen = new SettingsScreen(this, this->mainModel);
    //this->graphscreen = new GraphScreen(this);

    this->layout()->addWidget(this->sideMenu);
    this->layout()->addWidget(this->settingsScreen);
    //this->layout()->addWidget(this->graphscreen);

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



