#include "sideMenu.h"


SideMenu::SideMenu(QWidget* parent) : QFrame(parent)
{
    initStyle();

    initGetDataButton();
    initAnalyseButton();
    initSettingsButton();
    initHelpButton();

    initExitButton();


     //connect(this->getDataButton,SIGNAL(clicked()),mainController,SLOT(restartTest()));
}


SideMenu::~SideMenu()
{

}


void SideMenu::initStyle()
{
    this->setMaximumWidth(200);
    //this->setStyleSheet("QFrame { background-color: #bdbbb9 }");

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
    this->getDataButton = new QPushButton("", this);
    this->getDataButton->setObjectName("getData");
    this->getDataButton->setCheckable(true);


    QPixmap image(":/assets/play.png");
    QIcon icon(image);
    this->getDataButton->setIconSize(QSize(20, 20));
    this->getDataButton->setIcon(icon);
    this->getDataButton->setStyleSheet("text-align:left;");
    this->getDataButton->setLayout(new QHBoxLayout );

    QLabel* textLabel = new QLabel("Get Data");
    textLabel->setAlignment(Qt::AlignCenter);
    textLabel->setAttribute(Qt::WA_TransparentForMouseEvents, true);

    this->getDataButton->layout()->addWidget(textLabel);



    QSizePolicy* buttonSizePolicy = new QSizePolicy();
    buttonSizePolicy->setHorizontalPolicy(QSizePolicy::Expanding);
    this->getDataButton->setSizePolicy(*buttonSizePolicy);

    this->upperLayout->addWidget(this->getDataButton);
}

void SideMenu::initAnalyseButton()
{
    this->analyseButton = new QPushButton("Analyse", this);
    this->analyseButton->setCheckable(true);

    QSizePolicy* buttonSizePolicy = new QSizePolicy();
    buttonSizePolicy->setHorizontalPolicy(QSizePolicy::Expanding);
    this->analyseButton->setSizePolicy(*buttonSizePolicy);

    this->upperLayout->addWidget(this->analyseButton);
}

void SideMenu::initSettingsButton()
{
    this->settingsButton = new QPushButton("Settings", this);
    this->settingsButton->setCheckable(true);

    QSizePolicy* buttonSizePolicy = new QSizePolicy();
    buttonSizePolicy->setHorizontalPolicy(QSizePolicy::Expanding);
    this->settingsButton->setSizePolicy(*buttonSizePolicy);

    this->upperLayout->addWidget(this->settingsButton);
}

void SideMenu::initHelpButton()
{
    this->helpButton = new QPushButton("Help", this);
    this->helpButton->setCheckable(true);

    QSizePolicy* buttonSizePolicy = new QSizePolicy();
    buttonSizePolicy->setHorizontalPolicy(QSizePolicy::Expanding);
    this->helpButton->setSizePolicy(*buttonSizePolicy);

    this->upperLayout->addWidget(this->helpButton);
}

void SideMenu::initExitButton()
{
    this->exitButton = new QPushButton("Exit", this);
    this->exitButton->setObjectName("exit");
    this->exitButton->setCheckable(true);

    QSizePolicy* buttonSizePolicy = new QSizePolicy();
    buttonSizePolicy->setHorizontalPolicy(QSizePolicy::Expanding);
    this->exitButton->setSizePolicy(*buttonSizePolicy);

    this->bottomLayout->addWidget(this->exitButton);
}

