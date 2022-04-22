#include "settingsScreen.h"



SettingsScreen::SettingsScreen(QWidget* parent, SettingsModel* model) : QFrame(parent)
{
    this->settingsModel = model;
    initStyle();
    createNbTargetOption();
    createMinSizeTargetOption();
    createMaxSizeTargetOption();
}


SettingsScreen::~SettingsScreen()
{

}

void SettingsScreen::renderMinSizeTargetScene()
{
    this->minSizeTargetLabel->scene()->clear();

    double size = this->settingsModel->getMinSize();
    double posX = (this->minSizeTargetLabel->width()/2)-size/2;
    double posY = (this->minSizeTargetLabel->height()/2)-size/2;

    this->minSizeTargetLabel->scene()->addEllipse(posX, posY, size, size, QPen(QColor("red")),QBrush(QColor("red")));
}

void SettingsScreen::renderMaxSizeTargetScene()
{
    this->maxSizeTargetLabel->scene()->clear();

    double size = this->settingsModel->getMaxSize();
    double posX = (this->maxSizeTargetLabel->width()/2)-size/2;
    double posY = (this->maxSizeTargetLabel->height()/2)-size/2;

    this->maxSizeTargetLabel->scene()->addEllipse(posX, posY, size, size, QPen(QColor("red")),QBrush(QColor("red")));
}


void SettingsScreen::createMaxSizeTargetOption()
{
    this->maxSizeTargetSlider = new QSlider(this);
    this->maxSizeTargetSlider->setOrientation(Qt::Horizontal);
    this->maxSizeTargetSlider->setMaximumSize(400, 50);
    this->maxSizeTargetSlider->setTickInterval(1);
    this->maxSizeTargetSlider->setMinimum(5);
    this->maxSizeTargetSlider->setMaximum(150);

    this->maxSizeDescLabel = new QLabel(this);
    this->maxSizeDescLabel->setText("Maximum size of targets");
    this->maxSizeDescLabel->setAlignment(Qt::AlignHCenter);
    this->maxSizeDescLabel->setMaximumSize(400, 50);

    this->maxSizeTargetLabel = new QGraphicsView(this);
    this->maxSizeTargetLabel->setMinimumSize(200, 200);
    this->maxSizeTargetLabel->setMaximumSize(200, 200);
    this->maxSizeTargetLabel->setStyleSheet("border: 2px solid black");

    /******************************************************************/

    QGraphicsScene* scene = new QGraphicsScene(this->maxSizeTargetLabel);
    this->maxSizeTargetLabel->setScene(scene);
    renderMaxSizeTargetScene();

    /******************************************************************/

    QHBoxLayout* maxSizeOptionLayout = new QHBoxLayout();
    maxSizeOptionLayout->setAlignment(Qt::AlignLeft);
    maxSizeOptionLayout->setSpacing(50);

    QVBoxLayout* sliderLayout = new QVBoxLayout();

    maxSizeOptionLayout->addLayout(sliderLayout);
    sliderLayout->addWidget(this->maxSizeTargetSlider);
    sliderLayout->addWidget(this->maxSizeDescLabel);

    maxSizeOptionLayout->addWidget(this->maxSizeTargetLabel);

    this->mainLayout->addLayout(maxSizeOptionLayout);
}

void SettingsScreen::createMinSizeTargetOption()
{
    this->minSizeTargetSlider = new QSlider(this);
    this->minSizeTargetSlider->setOrientation(Qt::Horizontal);
    this->minSizeTargetSlider->setMaximumSize(400, 50);
    this->minSizeTargetSlider->setTickInterval(1);
    this->minSizeTargetSlider->setMinimum(5);
    this->minSizeTargetSlider->setMaximum(150);


    this->minSizeDescLabel = new QLabel(this);
    this->minSizeDescLabel->setText("Minimum size of targets");
    this->minSizeDescLabel->setAlignment(Qt::AlignHCenter);
    this->minSizeDescLabel->setMaximumSize(400, 50);
    //this->minSizeDescLabel->setStyleSheet("border: 2px solid black");

    this->minSizeTargetLabel = new QGraphicsView(this);
    this->minSizeTargetLabel->setMinimumSize(200, 200);
    this->minSizeTargetLabel->setMaximumSize(200, 200);
    this->minSizeTargetLabel->setStyleSheet("border: 2px solid black");

    /******************************************************************/

    QGraphicsScene* scene = new QGraphicsScene(this->minSizeTargetLabel);
    this->minSizeTargetLabel->setScene(scene);
    renderMinSizeTargetScene();

    /******************************************************************/

    QHBoxLayout* minSizeOptionLayout = new QHBoxLayout();
    minSizeOptionLayout->setAlignment(Qt::AlignLeft);
    minSizeOptionLayout->setSpacing(50);

    QVBoxLayout* sliderLayout = new QVBoxLayout();

    minSizeOptionLayout->addLayout(sliderLayout);
    sliderLayout->addWidget(this->minSizeTargetSlider);
    sliderLayout->addWidget(this->minSizeDescLabel);

    minSizeOptionLayout->addWidget(this->minSizeTargetLabel);

    this->mainLayout->addLayout(minSizeOptionLayout);

}


void SettingsScreen::createNbTargetOption()
{
    this->nbTargetSlider = new QSlider(this);
    this->nbTargetSlider->setOrientation(Qt::Horizontal);
    this->nbTargetSlider->setTickInterval(1);
    this->nbTargetSlider->setMinimum(1);
    this->nbTargetSlider->setMaximum(100);

    this->mainLayout->addWidget(this->nbTargetSlider);
    this->mainLayout->setAlignment(this->nbTargetSlider, Qt::AlignLeft);

}

void SettingsScreen::initStyle()
{
    this->setStyleSheet("QFrame { background-color: white }");

    this->mainLayout = new QVBoxLayout(this);

}
