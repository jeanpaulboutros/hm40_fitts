#ifndef HELP_H
#define HELP_H

#include <QStackedLayout>
#include <QFrame>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QPicture>

class Help : public QFrame
{
    Q_OBJECT
public:
    Help(QWidget* parent);
    ~Help();

    void initStyle();
    void displayStack();
    void checkBtnStatus();

    QStackedLayout* mainStack;
    QWidget* description;
    QWidget* variables;
    QWidget* graphs;
    QHBoxLayout* mainLayout;
    QPushButton* leftArrow;
    QPushButton* rightArrow;

public slots:
    void leftArrowClicked();
    void rightArrowClicked();

};

#endif // HELP_H
