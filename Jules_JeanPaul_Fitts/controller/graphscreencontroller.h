#ifndef GRAPHSCREENCONTROLLER_H
#define GRAPHSCREENCONTROLLER_H

#include "view/graphScreen.h"
#include "model/settingsModel.h"

#include <QObject>

class GraphScreenController : public QObject
{

    Q_OBJECT

public:

    GraphScreenController(GraphScreen* graphScreen, SettingsModel* settingsModel);
    ~GraphScreenController();

private:

    GraphScreen* graphScreen;
    SettingsModel* settingsModel;

    void addConnection();

private slots:

    void changeAValue();
    void changeBValue();
    void switchChartView();
};

#endif // GRAPHSCREENCONTROLLER_H
