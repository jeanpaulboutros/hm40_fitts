#include "graphScreen.h"


GraphScreen::GraphScreen(QWidget* parent, SettingsModel* settingsModel) : QFrame(parent)
{
    this->settingsModel = settingsModel;

    initStyle();
    createSliders();
    createChartView();
    createEquationView();
    initChronChart();
    initDistChart();

    this->chartView->setChart(this->chronChart);
}


GraphScreen::~GraphScreen()
{

}


void GraphScreen::createEquationView()
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
    this->chartView->setStyleSheet("background-color: white;");

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

    this->aValueLabel = new QLabel(aBox);
    printAValue();
    aBoxLayout->addWidget(this->aValueLabel);


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

    this->bValueLabel = new QLabel(bBox);
    printBValue();
    bBoxLayout->addWidget(this->bValueLabel);

    this->sliderLayout->addWidget(bBox);
}

void GraphScreen::printAValue()
{
    this->aValueLabel->setText(QString::number(this->settingsModel->getA()));
}

void GraphScreen::printBValue()
{
    this->bValueLabel->setText(QString::number(this->settingsModel->getB()));
}

void GraphScreen::initStyle()
{
    this->setObjectName("graphScreen");
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(0);

    this->upperGraphLayout = new QHBoxLayout();
    mainLayout->addLayout(this->upperGraphLayout);

    this->sliderLayout = new QHBoxLayout();
    mainLayout->addLayout(this->sliderLayout);

}

void GraphScreen::initChronChart()
{
    this->chronChart = new QChart;
    this->chronChart->setAnimationOptions(QChart::AllAnimations);
    this->chronChart->createDefaultAxes();
    this->chronChart->setBackgroundBrush(QBrush(QColor(150,150,150,255)));
    this->chronChart->setBackgroundVisible(true);
    this->chronChart->legend()->hide();
    this->chronChart->setTitleBrush(QBrush(QColor(0,0,0,255)));
    this->chronChart->setTitle("Time to click against rank of target");

    QLineSeries* series = calculateExperimentalSeries();
    QValueAxis* axisX = generateAxisX();
    QValueAxis* axisY = generateAxisY();

    this->chronChart->addSeries(series);
    this->chronChart->setAxisX(axisX, series);
    this->chronChart->setAxisY(axisY, series);

    this->chronChart->setVisible(true);
}


QLineSeries* GraphScreen::calculateExperimentalSeries()
{
    int nbCible = 20;

    QLineSeries* expSeries = new QLineSeries;

    for(int i = 0; i < nbCible; ++i){
        double T = i*867;
        expSeries->append(i, T);
    }

    return expSeries;
}

QValueAxis* GraphScreen::generateAxisX()
{
    QPen dotted;
    dotted.setWidth(1);
    dotted.setColor(QColor(0,0,0));
    QVector<qreal> dashes;
    dashes << 4 << 4;
    dotted.setDashPattern(dashes);

    QValueAxis* axisX = new QValueAxis();
    axisX->setTickCount(20);
    axisX->setGridLinePen(dotted);
    axisX->setLabelsColor(QColor(255,255,255));
    axisX->setTitleText("rank of the target");

    return axisX;
}

QValueAxis *GraphScreen::generateAxisY()
{
    QPen dotted;
    dotted.setWidth(1);
    QVector<qreal> dashes;
    dashes << 4 << 4;
    dotted.setDashPattern(dashes);
    dotted.setColor(QColor(0,0,0));

    QValueAxis* axisY = new QValueAxis();
    //axisY->setTickCount(20);
    axisY->setGridLinePen(dotted);
    axisY->setLabelsColor(QColor(255,255,255));
    axisY->setTitleText("Time in millisecond");

    return axisY;
}


void GraphScreen::initDistChart()
{
    this->distChart = new QChart;
    this->distChart->setAnimationOptions(QChart::AllAnimations);
    this->distChart->createDefaultAxes();
    this->distChart->setBackgroundBrush(QBrush(QColor(150,0,0,255)));
    this->distChart->setBackgroundVisible(true);
    this->distChart->legend()->hide();
    this->distChart->setTitleBrush(QBrush(QColor(0,0,0,255)));
    this->distChart->setTitle("Time to click against distance of to reach to target");

    QLineSeries* series = calculateExperimentalSeries();
    QValueAxis* axisX = generateAxisX();
    QValueAxis* axisY = generateAxisY();

    this->distChart->addSeries(series);
    this->distChart->setAxisX(axisX, series);
    this->distChart->setAxisY(axisY, series);

    this->distChart->setVisible(true);
}

void GraphScreen::changeChartView()
{
    if(this->chartView->chart() == this->chronChart){
        this->chartView->setChart(this->distChart);
    }else{
        this->chartView->setChart(this->chronChart);
    }
}

































