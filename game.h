
#ifndef GAME_H
#define GAME_H

#include<QWidget>
#include<QPushButton>
#include<QBoxLayout>
#include<QLabel>
#include<vector>


class Game:public QWidget
{
private:
    std::vector<std::vector<QPushButton*>> field;
    QWidget* mainMenu;
    QLabel* label;
    QPushButton* clear;
    QPushButton* back;
    int currentPlayer;
    int free;
    int sizeOfField;
    void offField();
    bool isComputer;
    bool checkWin();
    void computerMove();
public:
    Game(QWidget* parent = nullptr,int size=3,bool isComputer = 0,QWidget* mainMenu = nullptr);
    void newGame();
    ~Game();


private slots:
    void ONclicked();
    void OnClearClicked();
    void OnBackClicked();

};

#endif // GAME_H
