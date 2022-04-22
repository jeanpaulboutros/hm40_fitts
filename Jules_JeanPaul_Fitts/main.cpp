#include "view/view.h"
#include "model/model.h"
#include "controller/controller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Model* m = new Model();
    View* v = new View(m);
    Controller* c = new Controller(m, v);

//    SaveController saveController;
//    saveController.test();

    v->loadStyleSheet(&a);
    v->show();

    return a.exec();
}
