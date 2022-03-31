#ifndef VIEW_H
#define VIEW_H

//#include "FittsView.h"
//#include "ResultsView.h"
#include "controller/controller.h"
#include <QGuiApplication>
//#include <QPolarChart>
#include <QScreen>
#include <QMainWindow>
#include<QStackedLayout>
#include<QLabel>

class controller;

class View : public QMainWindow
{
    Q_OBJECT
public:
    View(controller *controller);
    ~View();
    void initWindows(controller *controller);
private:
    void displayTitle(QLayout *mainLayout);

    QStackedLayout *mainStack;

    friend controller;

};

#endif // VIEW_H
