#ifndef GRAPHSCREEN_H
#define GRAPHSCREEN_H

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

    QSlider* aValueSlider;
    QSlider* bValueSlider;

    GraphScreen(QWidget* parent);
    ~GraphScreen();

    void createEquationView();
    void createChartView();
    void createSliders();
    void initStyle();

    void initChronChart();
    void createDistChart();

};


#endif // GRAPHSCREEN_H
