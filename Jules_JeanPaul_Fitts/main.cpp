#include "view/view.h"
#include "model/model.h"
#include "controller/savecontroller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SettingsModel* m = new SettingsModel();
    View* v = new View(m);
    Controller* c = new Controller(m, v);

    SaveController saveController;
    saveController.test();

    v->loadStyleSheet(&a);
    v->show();



    return a.exec();
}
