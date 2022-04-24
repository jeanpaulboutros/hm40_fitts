#include "fittstest.h"

#include<QGuiApplication>
#include<QScreen>

FittsTest::FittsTest(QWidget *parent, TestModel* testModel) : QFrame(parent){

    this->testModel= testModel;
    this->initStyle();
    this->displayTest();
    //this->updateTestMsg();
    this->displayStartButton();
    this->resizeScene();
    connect(this->startTestBtn, SIGNAL(clicked()),this, SLOT(startButtonClicked()));

    //connect(this->startTest,SIGNAL(clicked()),mainController,this->displayButton(graphicLayout));
    /*connect(this->graphicWidget, SIGNAL(mouseClicked(int,int)), mainController, SLOT(cibleClicked(int,int)));
    connect(this->saveBtn,SIGNAL(clicked()),mainController,SLOT(saveConfig()));
    connect(this->backBtn,SIGNAL(clicked()),mainController,SLOT(backToMenu()));
    connect(this->restartBtn,SIGNAL(clicked()),mainController,SLOT(restartTest()));*/

}

FittsTest::~FittsTest() {}

void FittsTest::initStyle(){

    this->setStyleSheet(".QFrame { background-color: white; border-radius : 10px; }");
    this->testLayout = new QVBoxLayout(this);
}

void FittsTest::displayTest(){
    this->graphicWidget = new GraphicWidget();
    this->graphicWidget->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff);
    this->graphicWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->scene = new QGraphicsScene;
    this->graphicWidget->setScene(this->scene);
    this->testLayout->addWidget(this->graphicWidget);

}

void FittsTest::displayStartButton(){
    qreal factor = QGuiApplication::primaryScreen()->logicalDotsPerInch()/120;
    QHBoxLayout *btnLayout = new QHBoxLayout();
    this->testLayout->addLayout(btnLayout);

    this->startTestBtn = new QPushButton("Start Test");
    this->startTestBtn->setStyleSheet("background-color : blue; color : black; font-size : "+QString::number(16*factor)+"px; font-weight : bold; padding : "+QString::number(16*factor)+"px");
    btnLayout->addWidget(startTestBtn);

}

void FittsTest::displayButtons(){
    qreal factor = QGuiApplication::primaryScreen()->logicalDotsPerInch()/120;
    QHBoxLayout *btnLayout = new QHBoxLayout(this);

    this->saveBtn = new QPushButton("Save");
    this->saveBtn->setStyleSheet("background-color : blue; color : black; font-size : "+QString::number(16*factor)+"px; font-weight : bold; padding : "+QString::number(16*factor)+"px");
    this->backBtn = new QPushButton("Return to Menu");
    this->backBtn->setStyleSheet("background-color : red; color : black; font-size : "+QString::number(16*factor)+"px; font-weight : bold; padding : "+QString::number(16*factor)+"px");
    this->restartBtn = new QPushButton("Restart");
    this->restartBtn->setStyleSheet("background-color : green; color : black; font-size : "+QString::number(16*factor)+"px; font-weight : bold; padding : "+QString::number(16*factor)+"px");

    btnLayout->addWidget(this->saveBtn);
    btnLayout->addWidget(this->restartBtn);
    btnLayout->addWidget(this->backBtn);
    btnLayout->setEnabled(true);
    this->testLayout->addLayout(btnLayout);

}

void FittsTest::resizeScene(){
    this->scene->setSceneRect(this->graphicWidget->x(), this->graphicWidget->y(), this->graphicWidget->width(), this->graphicWidget->height());
    this->graphicWidget->fitInView(this->scene->sceneRect());
}

void FittsTest::startButtonClicked(){

    this->startTestBtn->setVisible(false);
    this->startTestBtn->setEnabled(false);
    this->testLabel = new QLabel("Click on the <font color='blue'><strong>blue</strong></font> target to launch the test");
    this->testLayout->addWidget(testLabel);
    this->displayButtons();

    this->startTest();
}

void FittsTest::startTest(){

    TestModel* tm = new TestModel();
    TestController* tc = new TestController(this,tm);
    //this->updateTestMsg();
    this->saveBtn->setEnabled(false);
    this->saveBtn->setVisible(false);
    this->graphicWidget->setEnabled(true);
    tm->cercleSize.clear();
    tm->cercleCenter.clear();
    tm->clickPoints.clear();
    tm->times.clear();
    tm->cibleLeft = tm->nbCible;
    //tc->mainView->sideMenu->setEnabled(false);
    tc->initGame();

}
