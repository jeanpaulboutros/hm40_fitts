#include "settingsScreen.h"



SettingsScreen::SettingsScreen(QWidget* parent, SettingsModel* model) : QFrame(parent)
{
    this->model = model;
    initStyle();
    createNbTargetOption();
    createMinSizeTargetOption();
    createMaxSizeTargetOption();
}


SettingsScreen::~SettingsScreen()
{

}


void SettingsScreen::createMaxSizeTargetOption()
{
    this->maxSizeTargetSlider = new QSlider(this);
    this->maxSizeTargetSlider->setOrientation(Qt::Horizontal);
    this->maxSizeTargetSlider->setTickInterval(1);
    this->maxSizeTargetSlider->setMinimum(1);
    this->maxSizeTargetSlider->setMaximum(100);

    this->maxSizeDescLabel = new QLabel(this);
    this->maxSizeDescLabel->setText("Maximum size of targets");
    this->maxSizeDescLabel->setAlignment(Qt::AlignHCenter);
    this->maxSizeDescLabel->setMaximumHeight(50);

    this->maxSizeTargetLabel = new QLabel(this);
    this->maxSizeTargetLabel->setMinimumSize(200, 200);
    this->maxSizeTargetLabel->setMaximumSize(200, 200);
    this->maxSizeTargetLabel->setStyleSheet("border: 2px solid black");

    QHBoxLayout* maxSizeOptionLayout = new QHBoxLayout();

    QVBoxLayout* sliderLayout = new QVBoxLayout();
    sliderLayout->setAlignment(Qt::AlignCenter);

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
    this->minSizeTargetSlider->setTickInterval(1);
    this->minSizeTargetSlider->setMinimum(1);
    this->minSizeTargetSlider->setMaximum(100);

    this->minSizeDescLabel = new QLabel(this);
    this->minSizeDescLabel->setText("Maximum size of targets");
    this->minSizeDescLabel->setAlignment(Qt::AlignHCenter);
    this->minSizeDescLabel->setMaximumHeight(50);

    this->minSizeTargetLabel = new QLabel(this);
    this->minSizeTargetLabel->setMinimumSize(200, 200);
    this->minSizeTargetLabel->setMaximumSize(200, 200);
    this->minSizeTargetLabel->setStyleSheet("border: 2px solid black");

    QHBoxLayout* minSizeOptionLayout = new QHBoxLayout();

    QVBoxLayout* sliderLayout = new QVBoxLayout();
    sliderLayout->setAlignment(Qt::AlignCenter);

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
