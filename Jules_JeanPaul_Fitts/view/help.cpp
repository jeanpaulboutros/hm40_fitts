#include "help.h"

Help::Help(QWidget* parent) : QFrame(parent)
{
    this->initStyle();
    this->displayStack();
    this->checkBtnStatus();
    connect(this->leftArrow, SIGNAL(clicked()),this,SLOT(leftArrowClicked()));
    connect(this->rightArrow, SIGNAL(clicked()),this,SLOT(rightArrowClicked()));
}

Help::~Help(){

}

void Help::initStyle(){

    this->setStyleSheet("QFrame { background-color: white }");
    this->mainLayout = new QHBoxLayout(this);
}

void Help::displayStack(){
    this->description = new QWidget(this);
    QVBoxLayout* d = new QVBoxLayout(description);
    d->setSpacing(0);

    this->graphs = new QWidget(this);
    QVBoxLayout* g = new QVBoxLayout(graphs);

    //this->variables = new QWidget(this);
    //VBoxLayout* v= new QVBoxLayout(variables);

    this->mainStack = new QStackedLayout(this);

    this->leftArrow = new QPushButton(this);
    QPixmap leftArrowImage(":/assets/left-arrow.png");
    QIcon leftArrowIcon(leftArrowImage);
    this->leftArrow->setIcon(leftArrowIcon);
    this->leftArrow->setIconSize(leftArrowImage.rect().size()/2);
    this->mainLayout->addWidget(leftArrow);

    this->mainStack->addWidget(description);
    //this->mainStack->addWidget(variables);
    this->mainStack->addWidget(graphs);

    this->mainLayout->addLayout(mainStack);

    this->rightArrow = new QPushButton(this);
    QPixmap rightArrowImage(":/assets/right-arrow.png");
    QIcon rightArrowIcon(rightArrowImage);
    this->rightArrow->setIcon(rightArrowIcon);
    this->rightArrow->setIconSize(rightArrowImage.rect().size()/2);
    this->mainLayout->addWidget(this->rightArrow);

    QLabel* lawDescription = new QLabel(description);
    QLabel* title = new QLabel(description);
    QLabel* formula = new QLabel(description);
    d->addWidget(title);
    d->addWidget(formula);
    d->addWidget(lawDescription);

    title->setAlignment(Qt::AlignHCenter);
    title->setText("<strong> <font size = 100 ; font color = 'blue'>La loi de Fitts</font> </strong>");
    formula->setStyleSheet("image: url(:/assets/equation2.png);");
    formula->setWordWrap(false);
    formula->setAlignment(Qt::AlignHCenter);
    lawDescription->setText("La loi de Fitts permet d’évaluer le temps de pointage nécessaire sur une cible de largeur L à une distance D. La formule proposée par Paul Fitts est ci-dessus où T est le temps moyen de mouvement, a et b des constantes ajustées empiriquement, D la distance au centre de la cible (appelé aussi amplitude du mouvement) , L la largeur de la cible. Le but du programme donc est de permettre à l’utilisateur de calculer le temps moyen de son mouvement sur un nombre de cibles dont il précise, et de visualiser son résultat sous forme d’un graphe.");
    lawDescription->setWordWrap(true);
    lawDescription->setAlignment(Qt::AlignHCenter);

    QLabel* graphTitle = new QLabel(graphs);
    QLabel* graphDescription = new QLabel(graphs);
    g->addWidget(graphTitle);
    g->addWidget(graphDescription);
    graphTitle->setText("<strong> <font size = 100 ; font color = 'blue'>Comprendre les graphs!</font> </strong>");
    graphTitle->setAlignment(Qt::AlignHCenter);
    graphDescription->setText("Les graphes fournies comme résultats représentent le Temps mis par l'utilisateur pour atteindre chaque cible. On peut remarquer deux courbes : la première est théorique, basée sur la formule de la loi de fitts, la deuxième est expérimentale. La différence principale entre c'est deux courbes sont les valeurs des constantes a et b prédéfinies par l'utilisateur. La courbe est constituée d'autant de points que le nombre de cibles prédéfini par l'utilisateur.Chaque point de la courbe possède comme abscisse l'ensemble de la largeur de la cible aléatoire et la distance entre son pointeur et le centre de la cible. Le temps calculé par la formule pour chaque cible représente l'ordonnée ");
    graphDescription->setWordWrap(true);
    graphDescription->setAlignment(Qt::AlignHCenter);
    /*QLabel* varDescription = new QLabel(variables);
    varDescription->setText("HOHOHOHOHOHOHOHOHOHOHOHHHHHHHHOHOOOOOOOOOOOOOHHHHHHHHHOOOOOOOOOOOH");
    varDescription->setWordWrap(true);*/
}

void Help::leftArrowClicked(){
    this->mainStack->setCurrentIndex(this->mainStack->currentIndex()-1);
    this->checkBtnStatus();
}
void Help::rightArrowClicked(){

    this->mainStack->setCurrentIndex(this->mainStack->currentIndex()+1);
    this->checkBtnStatus();
}

void Help::checkBtnStatus(){
    if(this->mainStack->currentIndex()==0){
        this->leftArrow->setEnabled(false);
    }
    else{
        this->leftArrow->setEnabled(true);
    }
    if(this->mainStack->currentIndex()==2){
        this->rightArrow->setEnabled(false);
    }
    else{
        this->rightArrow->setEnabled(true);
    }
}
