#ifndef SETTINGSCONTROLLER_H
#define SETTINGSCONTROLLER_H

#include <QObject>
#include <QDebug>
#include "view/settingsScreen.h"
#include "model/settingsModel.h"

class SettingsController : public QObject
{

    Q_OBJECT

public:

    SettingsController(SettingsScreen* settingsScreen, SettingsModel* settingsModel);
    ~SettingsController();

private:

    SettingsModel* settingsModel;
    SettingsScreen* settingsScreen;

    void addSettingsConnection();

public slots:

    void changeNbOfTarget();
    void changeMinSizeTarget();
    void changeMaxSizeTarget();
};

#endif // SETTINGSCONTROLLER_H
