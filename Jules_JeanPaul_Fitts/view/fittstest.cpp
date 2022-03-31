#include "fittstest.h"
#include<QGuiApplication>

fittstest::fittstest(QStackedLayout *mainStack, Controller *controller)
{

    QWidget *testWidget = new QWidget;
    mainStack->addWidget(testWidget);
    qreal factor = QGuiApplication::primaryScreen()->logicalDotsPerInch()/120;
    testWidget->setStyleSheet("font-size : "+QString::number(16*factor)+"px");

    QHBoxLayout *bodyLayout = new QHBoxLayout(testWidget);

    this->controller =controller;

    QVBoxLayout *settingsLayout = new QVBoxLayout();
    bodyLayout->addLayout(settingsLayout,0);

    QHBoxLayout *graphicLayout = new QHBoxLayout();
    bodyLayout->addLayout(graphicLayout,3);

    this->displayTest(graphicLayout);
    this->displayButton(settingsLayout);

    connect(this->saveBtn,SIGNAL(clicked()),controller,SLOT(saveConfig()));
    connect(this->graphicWidget, SIGNAL(mouseClicked(int,int)), controller, SLOT(cibleClicked(int,int)));
};

fittstest::~fittstest() {};
