#ifndef FITTSTEST_H
#define FITTSTEST_H

#include "GraphicWidget.h"
#include "controller/testcontroller.h"
#include "model/testmodel.h"
#include "view/view.h"

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
#include <QFrame>

class TestController;
class TestModel;
class View;
class FittsTest :  public QFrame
{
    Q_OBJECT

public:
    FittsTest(QWidget *parent, TestModel* testModel) ;
    ~FittsTest();
    void resizeScene();

private:

    QPushButton *saveBtn;
    QPushButton *restartBtn;
    QPushButton *backBtn;
    QPushButton *startTestBtn;
    QLabel *testLabel;
    QLabel *targetsLeft;

    QVBoxLayout* testLayout;

    QGraphicsScene *scene;
    GraphicWidget *graphicWidget;
    TestController *testController;
    TestModel *testModel;
    View* mainView;

    void displayButtons();
    void displayTest();
    void initStyle();
    void displayStartButton();

public slots:
    void startButtonClicked();
    void startTest();
    friend TestController;
    friend TestModel;

};

#endif // FITTSTEST_H
