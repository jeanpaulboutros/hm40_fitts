#ifndef SETTINGSCONTROLLER_H
#define SETTINGSCONTROLLER_H

#include <QObject>
#include <QDebug>
#include "view/settingsScreen.h"

class SettingsController : public QObject
{

    Q_OBJECT

public:

    SettingsController(SettingsScreen* settingsScreen);
    ~SettingsController();

private:

    SettingsScreen* settingsScreen;

    void addSettingsConnection();

public slots:

    void changeNbOfTarget();
};

#endif // SETTINGSCONTROLLER_H
