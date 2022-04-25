#include "view/view.h"
#include "model/model.h"
#include "controller/savecontroller.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Model* m = new Model();
    View* v = new View(m);
    Controller* c = new Controller(m, v);

    v->loadStyleSheet(&a);
    v->show();

    /* Quand on switch en dark mode:
    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(53,53,53));
    qApp->setPalette(darkPalette);
    */


    return a.exec();
}
