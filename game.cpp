
#include "Game.h"


Game::Game(QWidget* parent,int size,bool isComputer,QWidget* mainMenu):QWidget(parent),mainMenu(mainMenu),sizeOfField(size),isComputer(isComputer)
{
    newGame();
}

void Game::newGame()
{

    free = sizeOfField * sizeOfField;
    currentPlayer = 1;

    field.resize(sizeOfField);


    QHBoxLayout* hLayout = new QHBoxLayout(this);
    QGridLayout* gLayout = new QGridLayout;
    QVBoxLayout* vLayout = new QVBoxLayout;
    gLayout->setSpacing(10);
    for(int i=0;i<sizeOfField;i++)
    {
        for(int j=0;j<sizeOfField;j++)
        {
            QPushButton* button = new QPushButton;
           // button->setMinimumSize(70,70);
            button->setStyleSheet("QPushButton {"
                                  "border: 1px solid black;"
                                  "background-color: #f5f5f5;"
                                  "}");
            field[i].push_back(button);
            button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
            gLayout->addWidget(button,i,j);
            connect(button,&QPushButton::clicked,this,&Game::ONclicked);



        }
    }

    label = new QLabel();
    label->setWordWrap(true);
    if(!isComputer)
    {
        label->setText("Player1");
    }
    else
    {
        label->setText("Player");
    }

    label->setStyleSheet("QLabel {"
                        " color: red;"
                        " background-color: white;"
                        " border: 1px solid #8e8e8e;"
                        " border-radius: 5px;"
                        " padding: 5px;"
                        " font-size: 64px; "
                        " color: red }");
    label->setAlignment(Qt::AlignCenter);
    hLayout->addLayout(gLayout,9);
    clear = new QPushButton("Clear");
    clear->setStyleSheet("QPushButton {"
            "background-color: #FF0000;"
            "border-radius: 5px;"
            "font-family: Arial, sans-serif;"
            "font-size: 20px;"
            "font-weight: bold;"
            "color: #FFFFFF;"
            "padding: 5px 15px;"
        "}"

            "QPushButton:hover {"
            "background-color: #FF3333;"
        "}"

            "QPushButton:pressed {"
            "background-color: #FF6666;"
                         "}");
    back = new QPushButton("Back To main Menu");
    back->setStyleSheet("QPushButton {"
                         "background-color: blue;"
                         "border-radius: 5px;"
                         "font-family: Arial, sans-serif;"
                         "font-size: 20px;"
                         "font-weight: bold;"
                         "color: #FFFFFF;"
                         "padding: 5px 15px;"
                         "}"

                         "QPushButton:hover {"
                         "background-color: rgb(0, 0, 127)"
                         "}"

                         "QPushButton:pressed {"
                         "background-color: rgb(85, 85, 255);"
                         "}");
    clear->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
    back->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
    vLayout->addWidget(label,12);
    vLayout->addWidget(clear,2);
     vLayout->addWidget(back,2);
    hLayout->addLayout(vLayout,7);


    label->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
    this->setMinimumSize(800,450);
    this->show();

    connect(clear,&QPushButton::clicked,this,&Game::OnClearClicked);
    connect(back,&QPushButton::clicked,this,&Game::OnBackClicked);


}

bool Game::checkWin()
{

    int i = 0;
    int j = 0;
    int kol = 0;

    while(i<sizeOfField - 1)
    {
        if(field[i][j]->text()!="" && field[i][j]->text()==field[i+1][j+1]->text()) kol++;
        else break;
        i++;
        j++;
    }
    if(kol == sizeOfField - 1) return true;

    i = 0;
    j = sizeOfField - 1;
    kol = 0;

    while(i<sizeOfField - 1)
    {
        if(field[i][j]->text()!="" && field[i][j]->text()==field[i+1][j - 1]->text()) kol++;
        else break;
        j--;
        i++;
    }
    if(kol == sizeOfField - 1) return true;

    for(i = 0;i<sizeOfField;i++)
    {
        kol = 0;
        for(j = 0;j<sizeOfField - 1;j++)
        {
             if(field[i][j]->text()!="" && field[i][j]->text()==field[i][j+1]->text()) kol++;
             else break;
        }
        if(kol == sizeOfField - 1) return true;
    }

    for(j = 0;j<sizeOfField;j++)
    {
        kol = 0;
        for(i = 0;i<sizeOfField -1 ;i++)
        {
             if(field[i][j]->text()!="" && field[i][j]->text()==field[i+1][j]->text()) kol++;
             else break;
        }
        if(kol == sizeOfField - 1) return true;
    }


    return false;
}

void Game::ONclicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    button->setEnabled(false);
    if(currentPlayer == 1)
    {
        button->setText("X");

        button->setStyleSheet("QPushButton { font-family: 'Arial'; font-size: 55px; color: red; border: none; }");
        free --;

        if(!isComputer)
           label->setText("Player2");



        label->setStyleSheet("QLabel {"
                             " color: blue;"
                             " background-color: white;"
                             " border: 1px solid #8e8e8e;"
                             " border-radius: 5px;"
                             " padding: 5px;"
                             " font-size: 64px; "
                             " }");
        label->setAlignment(Qt::AlignCenter);
        qDebug()<<free;
        currentPlayer = 2;
        if(isComputer)
        {
           if(checkWin())
           {
               label->setText("Player\n is win");
               label->setStyleSheet("QLabel {"
                                    " color: red;"
                                    " background-color: white;"
                                    " border: 1px solid #8e8e8e;"
                                    " border-radius: 5px;"
                                    " padding: 5px;"
                                    " font-size: 64px; "
                                    " }");
               label->setAlignment(Qt::AlignCenter);
               offField();
               return;
           }

           if(free == 0)
           {
               label->setWordWrap(true);
               label->setText("  Draw  ");
               label->setStyleSheet("QLabel {"
                                    " color: grey;"
                                    " background-color: white;"
                                    " border: 1px solid #8e8e8e;"
                                    " border-radius: 5px;"
                                    " padding: 5px;"
                                    " font-size: 64px; "
                                    " }");
               label->setAlignment(Qt::AlignCenter);
               offField();
               return;
           }

             computerMove();
             free--;


             qDebug()<<free;
             if(checkWin())
             {
                     label->setText("Comp\n is win");
                     label->setStyleSheet("QLabel {"
                                          " color: Blue;"
                                          " background-color: white;"
                                          " border: 1px solid #8e8e8e;"
                                          " border-radius: 5px;"
                                          " padding: 5px;"
                                          " font-size: 64px; "
                                          " }");
                     label->setAlignment(Qt::AlignCenter);
                     offField();
                     return;
             }

             currentPlayer = 1;
             label->setText("Player");
             label->setStyleSheet("QLabel {"
                                  " color: red;"
                                  " background-color: white;"
                                  " border: 1px solid #8e8e8e;"
                                  " border-radius: 5px;"
                                  " padding: 5px;"
                                  " font-size: 64px; "
                                  " }");
             label->setAlignment(Qt::AlignCenter);
        }

    }
    else if(!isComputer)
    {
        button->setText("O");
        button->setStyleSheet("QPushButton { font-family: 'Arial'; font-size: 55px; color: blue; border: none; }");
        free --;
        label->setWordWrap(true);
        label->setText("Player1");
        label->setStyleSheet("QLabel {"
                             " color: red;"
                             " background-color: white;"
                             " border: 1px solid #8e8e8e;"
                             " border-radius: 5px;"
                             " padding: 5px;"
                             " font-size: 64px; "
                             " }");
        label->setAlignment(Qt::AlignCenter);
        qDebug()<<free;
        currentPlayer = 1;
    }





    if(checkWin())
    {
        //QMessageBox* box = new QMessageBox;
        if(currentPlayer ==2)
        {
             label->setText("Player1\n is win");
             label->setStyleSheet("QLabel {"
                                  " color: red;"
                                  " background-color: white;"
                                  " border: 1px solid #8e8e8e;"
                                  " border-radius: 5px;"
                                  " padding: 5px;"
                                  " font-size: 64px; "
                                  " }");
             label->setAlignment(Qt::AlignCenter);
        }
        else
        {

              label->setText("Player2\n is win");


             label->setStyleSheet("QLabel {"
                                  " color: blue;"
                                  " background-color: white;"
                                  " border: 1px solid #8e8e8e;"
                                  " border-radius: 5px;"
                                  " padding: 5px;"
                                  " font-size: 64px; "
                                  " }");
              label->setAlignment(Qt::AlignCenter);
        }
        offField();
        for(int i =0 ;i<sizeOfField;i++)
        {
             for(int j = 0;j<sizeOfField;j++)
             {
                 qDebug()<<field[i][j]->text();
             }
        }
        return ;
    }


    if(free==0)
    {

        label->setWordWrap(true);
        label->setText("  Draw  ");
        label->setStyleSheet("QLabel {"
                             " color: grey;"
                             " background-color: white;"
                             " border: 1px solid #8e8e8e;"
                             " border-radius: 5px;"
                             " padding: 5px;"
                             " font-size: 64px; "
                             " }");
        label->setAlignment(Qt::AlignCenter);
        offField();
    }
}

void Game::offField()
{
    for(int i = 0;i < sizeOfField;i++)
    {
        for(int j = 0;j < sizeOfField;j++)
        {
             field[i][j]->setEnabled(false);
        }
    }
}

void Game::computerMove()
{
    int i = 0;
    int j = 0;
    int kol = 0;



    while(i<sizeOfField)
    {
        if(field[i][j]->text()=="O") kol++;
        i++;
        j++;
    }
    if(kol == sizeOfField -1)
    {
        i = 0;
        j = 0;
        while(i<sizeOfField)
        {
             if(field[i][j]->text()=="") {field[i][j]->setText("O");
                 field[i][j]->setEnabled(false); qDebug()<<"1: "<<i<<" "<<j;
                 field[i][j]->setStyleSheet("QPushButton { font-family: 'Arial'; font-size: 55px; color: blue; border: none; }");
                 return;}

             i++;
             j++;
        }
    }

    i = 0;
    j = sizeOfField - 1;
    kol = 0;

    while(i<sizeOfField)
    {
        if(field[i][j]->text() == "O") kol++;
        j--;
        i++;
    }
    if(kol == sizeOfField - 1)
    {
        i = 0;
        j = sizeOfField - 1;
        while(i<sizeOfField)
        {
             if(field[i][j]->text() == "") {field[i][j]->setText("O");field[i][j]->setEnabled(false); qDebug()<<"2 "<<i<<" "<<j;
                 field[i][j]->setStyleSheet("QPushButton { font-family: 'Arial'; font-size: 55px; color: blue; border: none; }");
                 return;}

             j--;
             i++;
        }
    }


    for(i = 0;i<sizeOfField;i++)
    {
        kol = 0;
        for(j = 0;j<sizeOfField;j++)
        {
             if(field[i][j]->text()=="O" ) kol++;
        }
        if(kol == sizeOfField - 1)
        {
             for(j = 0;j<sizeOfField ;j++)
             {
                 if(field[i][j]->text()=="") {
                     field[i][j]->setText("O");
                     field[i][j]->setStyleSheet("QPushButton { font-family: 'Arial'; font-size: 55px; color: blue; border: none; }");
                     qDebug()<<"3 "<<i<<" "<<j;
                     field[i][j]->setEnabled(false);
                     return;
                 }

             }
        }
    }

    for(j = 0;j<sizeOfField;j++)
    {
        kol = 0;
        for(i = 0;i<sizeOfField ;i++)
        {
             if(field[i][j]->text()=="O" ) kol++;
        }
        if(kol == sizeOfField - 1)
        {
             for(i = 0;i<sizeOfField ;i++)
             {
                 if(field[i][j]->text()=="")
                 {field[i][j]->setText("O");
                     field[i][j]->setStyleSheet("QPushButton { font-family: 'Arial'; font-size: 55px; color: blue; border: none; }");
                 qDebug()<<"4 "<<i<<" "<<j;
                     field[i][j]->setEnabled(false);
                 return;
              }

             }
        }
    }


     i = 0;
     j = 0;
     kol = 0;

    while(i<sizeOfField)
    {
        if(field[i][j]->text()=="X") kol++;
        i++;
        j++;
    }
    if(kol == sizeOfField -1)
    {
        i = 0;
        j = 0;
        while(i<sizeOfField)
        {
             if(field[i][j]->text()=="") {field[i][j]->setText("O");
              field[i][j]->setStyleSheet("QPushButton { font-family: 'Arial'; font-size: 55px; color: blue; border: none; }");
              field[i][j]->setEnabled(false); qDebug()<<"5 "<<i<<" "<<j;return;}

             i++;
             j++;
        }
    }

    i = 0;
    j = sizeOfField - 1;
    kol = 0;

    while(i<sizeOfField)
    {
        if(field[i][j]->text() == "X") kol++;
        j--;
        i++;
    }
    if(kol == sizeOfField - 1)
    {
        i = 0;
        j = sizeOfField - 1;
        while(i<sizeOfField)
        {
             if(field[i][j]->text() == "") {field[i][j]->setText("O");
              field[i][j]->setStyleSheet("QPushButton { font-family: 'Arial'; font-size: 55px; color: blue; border: none; }");
              field[i][j]->setEnabled(false);qDebug()<<"6 "<<i<<" "<<j; return;}

             j--;
             i++;
        }
    }


    for(i = 0;i<sizeOfField;i++)
    {
        kol = 0;
        for(j = 0;j<sizeOfField ;j++)
        {
             qDebug()<<field[i][j]->text();
             if(field[i][j]->text()=="X" ) kol++;
             qDebug()<<"kol "<<kol;
        }
        if(kol == sizeOfField - 1)
        {

             for(j = 0;j<sizeOfField ;j++)
             {

                 qDebug()<<field[i][j]->text();
                 if(field[i][j]->text()=="")
                 {field[i][j]->setText("O");
                 field[i][j]->setStyleSheet("QPushButton { font-family: 'Arial'; font-size: 55px; color: blue; border: none; }");
                 qDebug()<<"7 "<<i<<" "<<j;
                 field[i][j]->setEnabled(false);
                 return;}
             }
        }
    }

    for(j = 0;j<sizeOfField;j++)
    {
        kol = 0;
        for(i = 0;i<sizeOfField ;i++)
        {
             if(field[i][j]->text()=="X" ) kol++;
        }
        if(kol == sizeOfField - 1)
        {
             for(i = 0;i<sizeOfField ;i++)
             {
                 if(field[i][j]->text()=="")
                 {qDebug()<<field[i][j]->text();field[i][j]->setText("O");
                 field[i][j]->setStyleSheet("QPushButton { font-family: 'Arial'; font-size: 55px; color: blue; border: none; }");
                 qDebug()<<"8 "<<i<<" "<<j;
                 field[i][j]->setEnabled(false);
                 return;
                 }
             }
        }
    }

    i  = rand()%sizeOfField;
    j = rand()%sizeOfField;

    while(field[i][j]->text()!="")
    {
        i  = rand()%sizeOfField;
        j = rand()%sizeOfField;
    }

    field[i][j]->setText("O");
    field[i][j]->setEnabled(false);
    field[i][j]->setStyleSheet("QPushButton { font-family: 'Arial'; font-size: 55px; color: blue; border: none; }");

    qDebug()<<"9 "<<i<<" "<<j;

    for(int i =0 ;i<sizeOfField;i++)
    {
        for(int j = 0;j<sizeOfField;j++)
        {
             qDebug()<<field[i][j]->text();
        }
    }
}

Game::~Game()
{
    delete label;
}

void Game::OnClearClicked()
{

    for(int i = 0;i<sizeOfField;i++)
    {
        for(int j = 0;j<sizeOfField;j++)
        {
             field[i][j]->setText("");
             field[i][j]->setEnabled(true);
             field[i][j]->setStyleSheet("QPushButton {"
                                   "border: 1px solid black;"
                                   "background-color: #f5f5f5;"
                                   "}");
        }
    }
    free  = sizeOfField * sizeOfField;
    currentPlayer = 1;

    if(!isComputer)
    {
        label->setText("Player1");
    }
    else
    {
        label->setText("Player");
    }

    label->setStyleSheet("QLabel {"
                         " color: red;"
                         " background-color: white;"
                         " border: 1px solid #8e8e8e;"
                         " border-radius: 5px;"
                         " padding: 5px;"
                         " font-size: 64px; "
                         " color: red }");
    label->setAlignment(Qt::AlignCenter);



}

void Game::OnBackClicked()
{
    this->hide();
    mainMenu->show();
}








