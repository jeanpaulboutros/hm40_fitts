#include "view.h"
View::View() : QFrame(0)
{
    initWindows();

    this->sideMenu = new SideMenu(this);
    this->layout()->addWidget(this->sideMenu);

    this->graphscreen = new GraphScreen(this);
    this->layout()->addWidget(this->graphscreen);

}

View::View(Controller *mainController){
    this->initWindows(mainController);
};


View::~View()
{

}

void View::initWindows()
{
    this->setWindowTitle("Fitts");
    this->setLayout(new QHBoxLayout());
}

void View::initWindows(Controller *mainController){
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    this->setWindowState(Qt::WindowMaximized);
    qreal factor = QGuiApplication::primaryScreen()->logicalDotsPerInch()/120;

    QWidget *mainWidget = new QWidget;
    mainWidget->setFixedHeight(screenGeometry.height()-30*factor);
    mainWidget->setFixedWidth(screenGeometry.width()-30*factor);
    //this->setCentralWidget(mainWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(mainWidget);
    mainLayout->setMargin(0);

    this->displayTitle(mainLayout);

    this->mainStack = new QStackedLayout;
    mainLayout->addLayout(mainStack);

    this->fittsTest = new FittsTest(mainStack, mainController);
}

void View::displayTitle(QLayout *mainLayout){
    QLabel *label = new QLabel("Test de la loi de Fitts");
    label->setAlignment(Qt::AlignCenter);
    qreal factor = QGuiApplication::primaryScreen()->logicalDotsPerInch()/120;
    label->setFont(QFont("Arial",20*factor));
    mainLayout->addWidget(label);
    label->setStyleSheet("background-color : #ddd;");
    label->setFixedHeight(90*factor);
}

