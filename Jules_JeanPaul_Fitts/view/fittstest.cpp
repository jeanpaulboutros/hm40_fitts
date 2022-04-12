#include "fittstest.h"
#include<QGuiApplication>
#include<QScreen>

FittsTest::FittsTest(QStackedLayout *mainStack, Controller *mainController){

    QWidget *testWidget = new QWidget;
    mainStack->addWidget(testWidget);
    qreal factor = QGuiApplication::primaryScreen()->logicalDotsPerInch()/120;
    testWidget->setStyleSheet("border :3px solid black; border-radius:10px;font-size : "+QString::number(16*factor)+"px");

    QHBoxLayout *bodyLayout = new QHBoxLayout(testWidget);

    this->mainController = mainController;

    QVBoxLayout *graphicLayout = new QVBoxLayout();
    bodyLayout->addLayout(graphicLayout,3);
    graphicLayout->setContentsMargins(350,150,150,150);

    this->displayTest(graphicLayout);
    this->displayButton(graphicLayout);

    connect(this->graphicWidget, SIGNAL(mouseClicked(int,int)), mainController, SLOT(cibleClicked(int,int)));
    connect(this->saveBtn,SIGNAL(clicked()),mainController,SLOT(saveConfig()));
    connect(this->backBtn,SIGNAL(clicked()),mainController,SLOT(backToMenu()));
    connect(this->restartBtn,SIGNAL(clicked()),mainController,SLOT(restartTest()));

}

FittsTest::~FittsTest() {}


void FittsTest::displayButton(QBoxLayout *graphicLayout){
    qreal factor = QGuiApplication::primaryScreen()->logicalDotsPerInch()/120;
    QHBoxLayout *btnLayout = new QHBoxLayout;
    graphicLayout->addLayout(btnLayout);

    this->saveBtn = new QPushButton("Sauvegarder configuration");
    this->saveBtn->setStyleSheet("background-color : blue; color : black; font-size : "+QString::number(16*factor)+"px; font-weight : bold; padding : "+QString::number(16*factor)+"px");
    this->backBtn = new QPushButton("Revenir au Menu Principal");
    this->backBtn->setStyleSheet("background-color : red; color : black; font-size : "+QString::number(16*factor)+"px; font-weight : bold; padding : "+QString::number(16*factor)+"px");
    this->restartBtn = new QPushButton("ReCommencer le Test");
    this->restartBtn->setStyleSheet("background-color : green; color : black; font-size : "+QString::number(16*factor)+"px; font-weight : bold; padding : "+QString::number(16*factor)+"px");

    btnLayout->addWidget(this->saveBtn);
    btnLayout->addWidget(this->restartBtn);
    btnLayout->addWidget(this->backBtn);

}

void FittsTest::displayTest(QLayout *graphicLayout){
    this->graphicWidget = new GraphicWidget;
    graphicLayout->addWidget(this->graphicWidget);
    this->graphicWidget->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff);
    this->graphicWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->scene = new QGraphicsScene;
    this->graphicWidget->setScene(this->scene);
}

void FittsTest::resizeScene(){
    this->scene->setSceneRect(this->graphicWidget->x(), this->graphicWidget->y(), this->graphicWidget->width(), this->graphicWidget->height());
    this->graphicWidget->fitInView(this->scene->sceneRect());
}
