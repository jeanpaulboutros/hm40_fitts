#ifndef SAVECONTROLLER_H
#define SAVECONTROLLER_H

#include "view/view.h"
#include "model/savemodel.h"


class SaveController : public QObject
{
    Q_OBJECT

private:
    SaveModel* saveModel;
    SaveMenu* saveScreen;

public:
    SaveController(SaveModel* model, SaveMenu* saveScreen);
    ~SaveController();

public slots:

    void openMenu();

};

#endif // SAVECONTROLLER_H
