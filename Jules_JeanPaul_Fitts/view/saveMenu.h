#ifndef SAVEMENU_H
#define SAVEMENU_H

#include <QObject>
#include <QFrame>
#include <QIcon>
#include <QPixmap>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>

class SaveMenu : public QFrame
{
    Q_OBJECT

public:

    QPushButton* openSaveMenuButton;

    QVBoxLayout* savesLayout;


    SaveMenu(QWidget* parent);
    ~SaveMenu();

private:

    void createOpenSaveButton();
    void initStyle();

};




#endif // SAVEMENU_H
