#ifndef SIDEMENU_H
#define SIDEMENU_H

#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QVBoxLayout>

class SideMenu : public QFrame
{
    Q_OBJECT

public:

    QPushButton* getDataButton;
    QPushButton* analyseButton;
    QPushButton* settingsButton;
    QPushButton* helpButton;
    QPushButton* exitButton;

    QVBoxLayout* upperLayout;
    QVBoxLayout* bottomLayout;

    SideMenu(QWidget* parent);
    ~SideMenu();



private:

    void initStyle();

    void initGetDataButton();
    void initAnalyseButton();
    void initSettingsButton();
    void initHelpButton();
    void initExitButton();

};




#endif // SIDEMENU_H
