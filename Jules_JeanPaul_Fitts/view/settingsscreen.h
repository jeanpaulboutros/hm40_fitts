#ifndef SETTINGSSCREEN_H
#define SETTINGSSCREEN_H

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

    SettingsScreen(QWidget* parent);
    ~SettingsScreen();

private:

    void createMaxSizeTargetOption();
    void createMinSizeTargetOption();
    void createNbTargetOption();
    void initStyle();
};

#endif // SETTINGSSCREEN_H