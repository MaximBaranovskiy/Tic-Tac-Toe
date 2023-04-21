
#ifndef WIDGET_H
#define WIDGET_H

#include "ChooseWindow.h"
#include "Game.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget

{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


private:
    Ui::Widget *ui;
    Game* game;
    ChooseWindow* choose;
private slots:
    void withPlayer2Clicked();
    void withComputerClicked();
    void ChooseFieldSize();

};

#endif // WIDGET_H
