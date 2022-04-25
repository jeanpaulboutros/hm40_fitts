#include "view.h"

View::View() : QFrame(0)
{


}

View::View(Model* mainModel) : View(){

    this->mainModel = mainModel;
    initWindows();

    this->sideMenu = new SideMenu(this);
    this->saveMenu = new SaveMenu(this);
    this->settingsScreen = new SettingsScreen(this, this->mainModel->settingsModel);
    this->graphscreen = new GraphScreen(this, this->mainModel->settingsModel);
    this->fittsTest = new FittsTest(this,this->testModel);
    this->help = new Help(this);
    QWidget* centerWidget = new QWidget;
    this->mainStack = new QStackedLayout(centerWidget);
    mainStack->addWidget(fittsTest);
    mainStack->addWidget(settingsScreen);
    mainStack->addWidget(graphscreen);
    mainStack->addWidget(help);

    //this->graphscreen = new GraphScreen(this);


    this->layout()->addWidget(this->sideMenu);
    this->layout()->addWidget(centerWidget);
    this->layout()->addWidget(this->saveMenu);
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



