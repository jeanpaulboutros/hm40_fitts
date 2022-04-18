#include "view/view.h"
#include "model/model.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    View v;
    v.loadStyleSheet(&a);


    Model m;
    v.show();
    return a.exec();
}
