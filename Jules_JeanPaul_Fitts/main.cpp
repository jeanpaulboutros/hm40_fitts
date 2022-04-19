#include "view/view.h"
#include "model/model.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FittsModel* m = new FittsModel();
    View* v = new View(m);
    Controller* c = new Controller(m, v);


    v->show();
    return a.exec();
}
