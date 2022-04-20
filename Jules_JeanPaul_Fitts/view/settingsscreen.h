#ifndef SETTINGSSCREEN_H
#define SETTINGSSCREEN_H


#include "model/settingsModel.h"

#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QSlider>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>

class SettingsScreen : public QFrame
{

    Q_OBJECT

public:

    QVBoxLayout* mainLayout;

    QSlider* nbTargetSlider;
    QSlider* minSizeTargetSlider;
    QSlider* maxSizeTargetSlider;

    QLabel* minSizeTargetLabel;
    QLabel* maxSizeTargetLabel;
    QLabel* minSizeDescLabel;
    QLabel* maxSizeDescLabel;
    QLabel* nbTargetDesc;

    SettingsModel* model;

    SettingsScreen(QWidget* parent, SettingsModel* model);
    ~SettingsScreen();

private:

    void createMaxSizeTargetOption();
    void createMinSizeTargetOption();
    void createNbTargetOption();
    void initStyle();

};

#endif // SETTINGSSCREEN_H
