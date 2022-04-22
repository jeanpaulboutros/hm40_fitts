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
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QSizePolicy>

class SettingsScreen : public QFrame
{

    Q_OBJECT

public:

    QVBoxLayout* mainLayout;

    QSlider* nbTargetSlider;
    QSlider* minSizeTargetSlider;
    QSlider* maxSizeTargetSlider;

    QGraphicsView* minSizeTargetLabel;
    QGraphicsView* maxSizeTargetLabel;

    QLabel* minSizeDescLabel;
    QLabel* maxSizeDescLabel;
    QLabel* nbTargetDesc;

    SettingsModel* settingsModel;

    SettingsScreen(QWidget* parent, SettingsModel* model);
    ~SettingsScreen();

    void renderMinSizeTargetScene();
    void renderMaxSizeTargetScene();

private:

    void createMaxSizeTargetOption();
    void createMinSizeTargetOption();
    void createNbTargetOption();
    void initStyle();

};

#endif // SETTINGSSCREEN_H
