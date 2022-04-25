#ifndef GRAPHSCREEN_H
#define GRAPHSCREEN_H

#include "model/settingsModel.h"

#include <QObject>
#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSlider>
#include <QGroupBox>
#include <QtCharts>
#include <QPushButton>
#include <QPixmap>
#include <QIcon>
#include <QLabel>
#include <QBrush>
#include <QColor>
#include <QString>

class GraphScreen : public QFrame
{
    Q_OBJECT

public:

    QHBoxLayout* upperGraphLayout;
    QHBoxLayout* sliderLayout;

    QPushButton* leftArrow;
    QPushButton* rightArrow;

    QChartView* chartView;
    QChart* chronChart;
    QChart* distChart;

    QLineSeries* calculateExperimentalSeries();
    QValueAxis* generateAxisX();
    QValueAxis* generateAxisY();

    QSlider* aValueSlider;
    QLabel* aValueLabel;
    QSlider* bValueSlider;
    QLabel* bValueLabel;

    SettingsModel* settingsModel;

    GraphScreen(QWidget* parent, SettingsModel* settingsModel);
    ~GraphScreen();

    void createEquationView();
    void createChartView();
    void createSliders();
    void initStyle();
    void printAValue();
    void printBValue();

    void changeChartView();

private:
    void initDistChart();
    void initChronChart();
};


#endif // GRAPHSCREEN_H
