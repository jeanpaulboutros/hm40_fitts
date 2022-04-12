#ifndef GRAPHSCREEN_H
#define GRAPHSCREEN_H

#include <QObject>
#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSlider>
#include <QGroupBox>
#include <QChartView>
#include <QPushButton>
#include <QPixmap>
#include <QIcon>
#include <QLabel>

class GraphScreen : public QFrame
{
    Q_OBJECT

public:

    QHBoxLayout* upperGraphLayout;
    QHBoxLayout* sliderLayout;

    QPushButton* leftArrow;
    QPushButton* rightArrow;

    QtCharts::QChartView* chartView;

    QSlider* aValueSlider;
    QSlider* bValueSlider;

    GraphScreen(QWidget* parent);
    ~GraphScreen();

    void createEquation();
    void createChartView();
    void createSliders();
    void initStyle();


};


#endif // GRAPHSCREEN_H
