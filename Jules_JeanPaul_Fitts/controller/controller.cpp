#include "controller/controller.h"

Controller::Controller(Model* mainModel, View* mainView)
{
    this->model = mainModel;
    this->mainView = mainView;
    this->settingsController = new SettingsController(this->mainView->settingsScreen, this->model->settingsModel);
    this->saveController = new SaveController(this->model->saveModel);

    //this->start();
    //this->startSimulation();
}

Controller::~Controller()
{
}

void Controller::start() {
    this->mainView->show();
    this->mainView->fittsTest->resizeScene();

}

void Controller::startSimulation() {
    this->mainView->fittsTest->graphicWidget->setEnabled(true);
    this->initGame();
}

void Controller::quit() {
    QApplication::quit();
}

void Controller::cibleClicked(int x, int y) {
    if(this->model->settingsModel->cercleCenter.isEmpty()) {
        this->model->settingsModel->cibleLeft = this->model->settingsModel->nbCible;
        // Si vide alors premier click, on demarre le timer
        this->timer->start();

        // On démarre avec la première cible
        this->nextCible();
    }
    else {
        QPointF coords = this->mainView->fittsTest->graphicWidget->mapToScene(x,y);
        if(sqrt(pow(coords.x() - this->model->settingsModel->cercleCenter.last().x(),2) + pow(coords.y() - this->model->settingsModel->cercleCenter.last().y(),2)) <= this->model->settingsModel->cercleSize.last()/2) {
            // On stock le temps de click
            this->timer->restart();

            // On stock la position du click
            this->nextCible();
        }
    }
}

void Controller::nextCible() {
    if(!this->model->settingsModel->cercleCenter.isEmpty())
        this->model->settingsModel->cibleLeft--;

    QGraphicsScene *scene = this->mainView->fittsTest->scene;
    scene->clear();

    // On stop si c'est finis
    if(this->model->settingsModel->cibleLeft == 0) {
        this->finish();
        return;
    }

    // On génère la taille du cercle rouge
    // qrand() % ((high + 1) - low) + low;
    int size;

    if(this->model->settingsModel->minSize == this->model->settingsModel->maxSize){
        size = this->model->settingsModel->maxSize;
    }else{
        size = QRandomGenerator::global()->bounded(this->model->settingsModel->minSize, this->model->settingsModel->maxSize);
    }
    qreal factor = QGuiApplication::primaryScreen()->logicalDotsPerInch()/120;
    size*=factor;
    // Car on veut le rayon
    // On place le cercle dans la scene (Attention faut pas qu'il soit en dehors du cadre)
    int sceneW = int(this->mainView->fittsTest->scene->width());
    int sceneH = int(this->mainView->fittsTest->scene->height());
    qreal posX = QRandomGenerator::global()->bounded(size/2, sceneW-size);
    qreal posY = QRandomGenerator::global()->bounded(size/2, sceneH-size);

    // On stock les infos sur le cercle
    this->model->settingsModel->cercleCenter.append(QPoint(int(posX+size/2),int(posY+size/2)));
    this->model->settingsModel->cercleSize.append(size);

    // On place le cercle
    scene->addEllipse(posX, posY, size, size, QPen(QColor("red")),QBrush(QColor("red")));
}

void Controller::finish() {
    this->mainView->fittsTest->graphicWidget->setEnabled(false);
    this->mainView->mainStack->setCurrentIndex(1);
}

void Controller::initGame() {
    QGraphicsScene *scene = this->mainView->fittsTest->scene;
    scene->clear();
    qreal factor = QGuiApplication::primaryScreen()->logicalDotsPerInch()/120;

    qreal posX = scene->width() / 2;
    qreal posY = scene->height() / 2;
    int size = 100*factor;

    scene->addEllipse(posX - (size / 2), posY - (size / 2), size, size, QPen(QColor("green")),QBrush(QColor("green")));
    this->timer = new QElapsedTimer();
}

void Controller::saveConfig(){
    QSettings settings("Garrido", "Fitts2.0");

    settings.setValue("a", this->model->settingsModel->a);
    settings.setValue("b", this->model->settingsModel->b);

    settings.setValue("nbCible", this->model->settingsModel->nbCible);
    settings.setValue("minSize", this->model->settingsModel->minSize);
    settings.setValue("maxSize", this->model->settingsModel->maxSize);
}

double Controller::getA(){
    return this->model->settingsModel->a;
}

double Controller::getB(){
    return this->model->settingsModel->b;
}

int Controller::getNbCible(){
    return this->model->settingsModel->nbCible;
}

void Controller::restartTest(){
    this->model->settingsModel->cercleSize.clear();
    this->model->settingsModel->cercleCenter.clear();
    this->mainView->mainStack->setCurrentIndex(0);
    this->startSimulation();
}

void Controller::backToMenu(){
    QApplication::quit();
}
