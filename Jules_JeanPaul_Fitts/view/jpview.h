#ifndef JPVIEW_H
#define JPVIEW_H


#include "fittstest.h"
#include <QGuiApplication>
#include <QScreen>
#include <QMainWindow>
#include <QStackedLayout>


class FittsTest;
class Controller;

class View: public QMainWindow
{
    Q_OBJECT
public:
    View(Controller *mainController);
    ~View();
    void initWindows(Controller *mainController);
private:
    void displayTitle(QLayout *mainLayout);

    FittsTest *fittsTest;
    QStackedLayout *mainStack;

    friend Controller;

};

#endif // JPVIEW_H
