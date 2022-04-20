#include "saveMenu.h"

SaveMenu::SaveMenu(QWidget* parent) : QFrame(parent)
{
    initStyle();
    createOpenSaveButton();
}

SaveMenu::~SaveMenu()
{

}

void SaveMenu::createOpenSaveButton()
{
    this->openSaveMenuButton = new QPushButton(this);
    QPixmap image(":/assets/save.png");
    QIcon icon(image);
    this->openSaveMenuButton->setIcon(icon);

    this->layout()->addWidget(this->openSaveMenuButton);
}

void SaveMenu::initStyle()
{
    //this->setStyleSheet("QFrame { background-color: #bdbbb9 }");
    this->setMaximumWidth(75);
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(0);
    mainLayout->setAlignment(Qt::AlignTop);
}
