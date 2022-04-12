#include "sideMenu.h"


SideMenu::SideMenu(QWidget* parent) : QFrame(parent)
{
    initStyle();

    initGetDataButton();
    initAnalyseButton();
    initSettingsButton();
    initHelpButton();

    initExitButton();
}


SideMenu::~SideMenu()
{

}


void SideMenu::initStyle()
{
    this->setMaximumWidth(200);
    this->setStyleSheet("QFrame { background-color: grey }");

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(0);

    this->upperLayout = new QVBoxLayout();
    upperLayout->setAlignment(Qt::AlignTop);
    mainLayout->addLayout(upperLayout);

    this->bottomLayout = new QVBoxLayout();
    bottomLayout->setAlignment(Qt::AlignBottom);
    mainLayout->addLayout(bottomLayout);

}


void SideMenu::initGetDataButton()
{
    this->getDataButton = new QPushButton("Get Data", this);

    QSizePolicy* buttonSizePolicy = new QSizePolicy();
    buttonSizePolicy->setHorizontalPolicy(QSizePolicy::Expanding);
    this->getDataButton->setSizePolicy(*buttonSizePolicy);

    this->upperLayout->addWidget(this->getDataButton);
}

void SideMenu::initAnalyseButton()
{
    this->analyseButton = new QPushButton("Analyse", this);

    QSizePolicy* buttonSizePolicy = new QSizePolicy();
    buttonSizePolicy->setHorizontalPolicy(QSizePolicy::Expanding);
    this->analyseButton->setSizePolicy(*buttonSizePolicy);

    this->upperLayout->addWidget(this->analyseButton);
}

void SideMenu::initSettingsButton()
{
    this->settingsButton = new QPushButton("Settings", this);

    QSizePolicy* buttonSizePolicy = new QSizePolicy();
    buttonSizePolicy->setHorizontalPolicy(QSizePolicy::Expanding);
    this->settingsButton->setSizePolicy(*buttonSizePolicy);

    this->upperLayout->addWidget(this->settingsButton);
}

void SideMenu::initHelpButton()
{
    this->helpButton = new QPushButton("Help", this);

    QSizePolicy* buttonSizePolicy = new QSizePolicy();
    buttonSizePolicy->setHorizontalPolicy(QSizePolicy::Expanding);
    this->helpButton->setSizePolicy(*buttonSizePolicy);

    this->upperLayout->addWidget(this->helpButton);
}

void SideMenu::initExitButton()
{
    this->exitButton = new QPushButton("Exit", this);

    QSizePolicy* buttonSizePolicy = new QSizePolicy();
    buttonSizePolicy->setHorizontalPolicy(QSizePolicy::Expanding);
    this->exitButton->setSizePolicy(*buttonSizePolicy);

    this->bottomLayout->addWidget(this->exitButton);
}

