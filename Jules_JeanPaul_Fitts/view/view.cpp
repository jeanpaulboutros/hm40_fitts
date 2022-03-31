#include "view.h"
#include "controller/controller.h"

View::View(controller *controller) : QMainWindow(){
    this->initWindows(controller);
}

View::~View(){};

void View::initWindows(controller *controller){
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenForm = screen->geometry();
    this-> setWindowState(Qt::WindowMaximized);
    qreal factor = QGuiApplication::primaryScreen()->logicalDotsPerInch()/120;

    QWidget *mainWidget = new QWidget;
    mainWidget->setFixedHeight(screenForm.height()-30*factor);
    mainWidget->setFixedWidth(screenForm.width());
    this->setCentralWidget(mainWidget);


    QVBoxLayout *mainLayout = new QVBoxLayout(mainWidget);
    mainLayout->setMargin(0);

    this->displayTitle(mainLayout);

    this->mainStack = new QStackedLayout;
    mainLayout->addLayout(mainStack);
}

void View::displayTitle(QLayout *mainLayout){
    QLabel *label = new QLabel("This is a test of Fitts' Law");
    label->setAlignment(Qt::AlignCenter);
    qreal factor = QGuiApplication::primaryScreen()->logicalDotsPerInch()/120;
    label->setFont(QFont("Arial",20*factor));
    mainLayout->addWidget(label);
    label->setStyleSheet("background-color : #98C8FF;");
    label->setFixedHeight(90*factor);

}


