
#ifndef CHOOSEWINDOW_H
#define CHOOSEWINDOW_H

#include "QBoxLayout"
#include "QLabel"
#include "QPushButton"
#include <QDialog>
#include<QLineEdit>


class ChooseWindow : public QWidget
{

private:
    QLineEdit* line;
    int sizeOfField;
    QWidget* mainMenu;
public:
    ChooseWindow(QWidget* mainMenu = nullptr,QWidget * parent = nullptr);
    int getSize();
    ~ChooseWindow();
private slots:
    void OKclicked();
};

#endif // CHOOSEWINDOW_H
