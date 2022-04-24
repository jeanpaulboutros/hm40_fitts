#include "testcontroller.h"

TestController::TestController(FittsTest* fittsTest, TestModel* testModel)
{
    this->fittsTest= fittsTest;
    this->fittsTest->show();
    this->testModel=testModel;
    this->sm= new SettingsModel();

    connect(this->fittsTest->graphicWidget, SIGNAL(mouseClicked(int,int)), this, SLOT(cibleClicked(int,int)));
    connect(this->fittsTest->restartBtn, SIGNAL(clicked()),this,SLOT(restartTest()));

}

TestController::~TestController()
{

}

//Functions
void TestController::initGame(){
    QGraphicsScene *scene = this->fittsTest->scene;
    scene->clear();

    if(this->testModel->maxSize >= this->fittsTest->graphicWidget->width() / 2)
        this->testModel->maxSize = this->fittsTest->graphicWidget->width() / 2;

    if(this->testModel->maxSize >= this->fittsTest->graphicWidget->height() / 2)
        this->testModel->maxSize = this->fittsTest->graphicWidget->height() / 2;

    qreal posX = scene->width() / 2;
    qreal posY = scene->height() / 2;
    int size = 100;

    scene->addEllipse(posX - (size / 2), posY - (size / 2), size, size, QPen(QColor("blue")),QBrush(QColor("blue")));
}

void TestController::nextCible(){

    if(!this->testModel->cercleCenter.isEmpty())
        this->testModel->cibleLeft--;

    QGraphicsScene *scene = this->fittsTest->scene;
    scene->clear();

    // Stop if nb of targets left is 0
    if(this->testModel->cibleLeft == 0) {
        this->finish();
        return;
    }

    // Generate red circle size
    // qrand() % ((high + 1) - low) + low;
    int size =  QRandomGenerator::global()->bounded(((this->testModel->maxSize + 1) - this->testModel->minSize))  + this->testModel->minSize;
    // We need the radius
    // Place the circle in the scene (make sure its within the scene margins)
    int sceneW = int(this->fittsTest->scene->width());
    int sceneH = int(this->fittsTest->scene->height());

    double posX =  QRandomGenerator::global()->bounded(((sceneW - size) - size)) + size ;
    double posY =  QRandomGenerator::global()->bounded(((sceneH - size) - size)) + size ;

    // change circle data
    this->testModel->cercleCenter.append(QPoint(int(posX),int(posY)));
    this->testModel->cercleSize.append(size);

    // Place the circle
    scene->addEllipse(posX - (size / 2), posY - (size / 2), size, size, QPen(QColor("red")),QBrush(QColor("red")));
}

void TestController::finish(){
    this->mainView = new View();
    this->fittsTest->graphicWidget->setEnabled(false);
    this->fittsTest->saveBtn->setEnabled(true);
    this->fittsTest->saveBtn->setVisible(true);
    this->fittsTest->testLabel->setVisible(false);
    this->fittsTest->targetsLeft->setVisible(false);
    this->testModel->calculateResults();
}

//SLOTS
void TestController::restartTest(){
    this->testModel->cercleCenter.clear();
    this->testModel->cercleSize.clear();
    this->testModel->clickPoints.clear();
    this->testModel->times.clear();
    this->fittsTest->graphicWidget->setEnabled(true);
    this->testModel->nbCible=this->sm->getNbCible();
    this->testModel->cibleLeft = this->sm->getNbCible();
    this->fittsTest->testLabel->setVisible(true);
    this->fittsTest->targetsLeft->setVisible(true);
    this->fittsTest->startTest();

}

void TestController::cibleClicked(int x, int y){

    QString newText= QString("Click on the <font color='red'><strong>RED</strong></font> targets. Number of targets chosen : <strong> %1").arg(this->sm->getNbCible());
    QString targetsLeft = QString ("Targets left <strong> %1 </strong>").arg(this->testModel->cibleLeft-1);
    if(this->testModel->cercleCenter.isEmpty()) {
        // Si vide alors premier click, on demarre le timer
        this->timer = new QElapsedTimer;
        timer->start();

        // On démarre avec la première cible
        this->testModel->clickPoints.append(QPoint(x,y));
        this->nextCible();
        this->fittsTest->testLabel->setText(newText);
        this->fittsTest->targetsLeft->setText(targetsLeft);
    }
    else {
        this->fittsTest->testLabel->setText(newText);
        this->fittsTest->targetsLeft->setText(targetsLeft);
        QPointF coords = this->fittsTest->graphicWidget->mapToScene(x,y);
        if(sqrt(pow(coords.x() - this->testModel->cercleCenter.last().x(),2) + pow(coords.y() - this->testModel->cercleCenter.last().y(),2)) <= this->testModel->cercleSize.last() / 2) {
            this->testModel->clicks ++;
            // On stock le temps de click
            this->testModel->times.append(timer->elapsed());
            // On restart le chrono
            timer->restart();

            // On stock la position du click
            this->testModel->clickPoints.append(QPoint(x,y));
            this->nextCible();
        }
        else
        {
            this->testModel->failedClicks ++;
        }
    }
}

void TestController::startButtonClicked(){

    /*this->fittsTest->startTestBtn->setVisible(false);
    this->fittsTest->startTestBtn->setEnabled(false);
    this->fittsTest->displayButtons();
    this->startTest();*/
}

