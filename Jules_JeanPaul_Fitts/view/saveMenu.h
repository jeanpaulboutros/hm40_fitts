#ifndef SAVEMENU_H
#define SAVEMENU_H

#include "model/savemodel.h"
#include <QObject>
#include <QFrame>
#include <QIcon>
#include <QPixmap>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>

class SaveMenu : public QFrame
{
    Q_OBJECT

public:

    QList<QPushButton*> historyButtons;
    QPushButton* openSaveMenuButton;
    QVBoxLayout* savesLayout;
    QScrollArea* scrollArea;
    void handleOpenSaveButton();
    SaveMenu(QWidget* parent);
    ~SaveMenu();
    void populate(QList<SavedData> savedData);
private:
    bool isOpen;
    void createOpenSaveButton();
    void initStyle();

};




#endif // SAVEMENU_H
