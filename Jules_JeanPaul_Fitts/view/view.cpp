#include "view.h"


View::View() : QFrame(0)
{
    initWindows();

    this->sideMenu = new SideMenu(this);
    this->layout()->addWidget(this->sideMenu);

    this->graphscreen = new GraphScreen(this);
    this->layout()->addWidget(this->graphscreen);
}

View::~View()
{

}

void View::initWindows()
{
    this->setWindowTitle("Fitts");
    this->setLayout(new QHBoxLayout());
}


