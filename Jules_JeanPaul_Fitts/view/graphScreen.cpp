#include "graphScreen.h"

GraphScreen::GraphScreen(QWidget* parent) : QFrame(parent)
{
    initStyle();
    createSliders();
    createChartView();
    createEquation();
}


GraphScreen::~GraphScreen()
{

}


void GraphScreen::createEquation()
{
    QLabel* equation = new QLabel(this);
    QPixmap equationImage(":/assets/equation2.png");
    equation->setPixmap(equationImage);

    this->layout()->addWidget(equation);
    this->layout()->setAlignment(equation, Qt::AlignHCenter);
}

void GraphScreen::createChartView()
{
    this->leftArrow = new QPushButton(this);
    QPixmap leftArrowImage(":/assets/left-arrow.png");
    QIcon leftArrowIcon(leftArrowImage);
    this->leftArrow->setIcon(leftArrowIcon);
    this->leftArrow->setIconSize(leftArrowImage.rect().size()/2);
    this->upperGraphLayout->addWidget(this->leftArrow);

    /*****************************************************************/

    this->chartView = new QChartView(this);
    this->upperGraphLayout->addWidget(this->chartView);

    /*****************************************************************/

    this->rightArrow = new QPushButton(this);
    QPixmap rightArrowImage(":/assets/right-arrow.png");
    QIcon rightArrowIcon(rightArrowImage);
    this->rightArrow->setIcon(rightArrowIcon);
    this->rightArrow->setIconSize(rightArrowImage.rect().size()/2);
    this->upperGraphLayout->addWidget(this->rightArrow);
}


void GraphScreen::createSliders()
{
    QGroupBox* aBox = new QGroupBox("A", this);
    aBox->setMaximumSize(200, 100);

    QHBoxLayout* aBoxLayout = new QHBoxLayout();
    aBoxLayout->setAlignment(Qt::AlignCenter);
    aBox->setLayout(aBoxLayout);

    this->aValueSlider = new QSlider(Qt::Horizontal, aBox);
    this->aValueSlider->setTickInterval(1);
    this->aValueSlider->setTickPosition(QSlider::TicksLeft);
    this->aValueSlider->setMinimum(0);
    this->aValueSlider->setMaximum(10);
    aBoxLayout->addWidget(this->aValueSlider);

    this->sliderLayout->addWidget(aBox);

    /***************************************************************/

    QGroupBox* bBox = new QGroupBox("B", this);
    bBox->setMaximumSize(200, 100);

    QHBoxLayout* bBoxLayout = new QHBoxLayout();
    bBoxLayout->setAlignment(Qt::AlignCenter);
    bBox->setLayout(bBoxLayout);

    this->bValueSlider = new QSlider(Qt::Horizontal, bBox);
    this->bValueSlider->setTickInterval(1);
    this->bValueSlider->setTickPosition(QSlider::TicksLeft);
    this->bValueSlider->setMinimum(0);
    this->bValueSlider->setMaximum(10);
    bBoxLayout->addWidget(this->bValueSlider);

    this->sliderLayout->addWidget(bBox);
}


void GraphScreen::initStyle()
{
    this->setStyleSheet("QFrame { background-color: green }");

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(0);

    this->upperGraphLayout = new QHBoxLayout();
    mainLayout->addLayout(this->upperGraphLayout);

    this->sliderLayout = new QHBoxLayout();
    mainLayout->addLayout(this->sliderLayout);

}



