#include "saveMenu.h"

SaveMenu::SaveMenu(QWidget* parent) : QFrame(parent)
{
    initStyle();
    createOpenSaveButton();

}

SaveMenu::~SaveMenu()
{

}

void SaveMenu::handleOpenSaveButton() {
    this->isOpen = !this->isOpen;
    this->setMaximumWidth(this->isOpen ? 275 : 75);
}

void SaveMenu::createOpenSaveButton()
{
    this->openSaveMenuButton = new QPushButton(this);
    QPixmap image(":/assets/save.png");
    QIcon icon(image);
    this->openSaveMenuButton->setIcon(icon);

    this->layout()->addWidget(this->openSaveMenuButton);
}

void SaveMenu::initStyle()
{
    //this->setStyleSheet("QFrame { background-color: #bdbbb9 }");
    this->setMaximumWidth(75);

//    QScrollArea *scrollArea = new QScrollArea();
//    scrollArea->setWidgetResizable (true);
//    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
//    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(0);
    mainLayout->setAlignment(Qt::AlignTop);

//    scrollArea->setWidget(this);
}


void SaveMenu::populate(QList<SavedData> savedData){
    for (int i = 0; i < savedData.count(); i++) {
        SavedData data = savedData.at(i);
        QPushButton *btn = new QPushButton(this);
        btn->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);  // has no effect

        btn->setObjectName("saveButtonHistory");
        int testCount = savedData.count()-i;
        qint64 timestamp = data.times.at(0);
        QDateTime dateTime = QDateTime::fromSecsSinceEpoch(timestamp);
        btn->setText("Test n°" + QString::number(testCount) + "\n " + dateTime.toString());

        this->historyButtons.push_back(btn);
        this->layout()->addWidget(btn);
    }
}
