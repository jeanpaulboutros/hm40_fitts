#ifndef FITTSTEST_H
#define FITTSTEST_H

#include "view/graphicwidget.h"
#include "controller/controller.h"
#include <QStackedLayout>
#include <QPushButton>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QGroupBox>
#include <QScreen>


class Controller;
class GraphicWidget;

class fittstest : public QObject
{
public:
    fittstest(QStackedLayout *mainStack, Controller *mainController);
    ~fittstest();

    void disableAllSpins();
    void enableAllSpins();
    void updateValMinOfMaxSize();
    void updateValMaxOfMinSize();
    void resizeScene();
private:
    QPushButton *saveBtn;
    QPushButton *start;
    QPushButton *exit;

    GraphicWidget *graphicWidget;
    QGraphicsScene *scene;

    Controller *controller;
    void displayButton(QBoxLayout *settingsLayout);
    void displayTest(QLayout *graphicLayout);

    friend Controller;

};

#endif // FITTSTEST_H
