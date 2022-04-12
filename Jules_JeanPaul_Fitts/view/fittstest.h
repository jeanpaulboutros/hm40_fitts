#ifndef FITTSTEST_H
#define FITTSTEST_H

#include "Controller/controller.h"
#include "GraphicWidget.h"

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

class Controller;

class FittsTest :  public QObject
{
    Q_OBJECT

public:
    FittsTest(QStackedLayout *mainStack, Controller *mainController);
    ~FittsTest();

    void updateValMinOfMaxSize();
    void updateValMaxOfMinSize();
    void resizeScene();
private:
    QPushButton *saveBtn;
    QPushButton *restartBtn;
    QPushButton *backBtn;

    QGraphicsScene *scene;
    GraphicWidget *graphicWidget;
    Controller *mainController;

    void displayButton(QBoxLayout *settingsLayout);
    void displayTest(QLayout *graphicLayout);


    friend Controller;

};

#endif // FITTSTEST_H
