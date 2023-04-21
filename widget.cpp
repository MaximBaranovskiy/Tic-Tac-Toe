#include "widget.h"
#include "ui_widget.h"
#include"Game.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    choose = new ChooseWindow(this);
    choose->hide();
    game = nullptr;

    QVBoxLayout* vLayout = new QVBoxLayout();
    QHBoxLayout* hLayout = new QHBoxLayout(this);
    vLayout->setDirection(QBoxLayout::TopToBottom);
    vLayout->setAlignment(Qt::AlignCenter);

    QLabel* label = new QLabel("TIC-TAC-TOE");
    label->setAlignment(Qt::AlignCenter);

    QPushButton* button1 = new QPushButton("VS Player2");
    QPushButton* button2 = new QPushButton("VS Computer");
    QPushButton* button3 = new QPushButton("Choose size of field");

    setStyleSheet("QPushButton {"
                  "background-color: #2196F3;"
                  "color: white;"
                  "border-radius: 10px;"
                  "padding: 5px 10px;"
                  "font-size: 20px;"
                  "font-weight: 600;"
                  "}"
                  "QPushButton:hover {"
                  "background-color: #0D8ED9;"
                  "}"
                  "QPushButton:pressed {"
                  "background-color: rgb(0, 0, 127);"
                  "border: none;"
                  "}"
                  "QLabel{"
                  "font-family: Segoe Script;"
                  "font-size: 64px;"
                  "font-weight: bold;"
                  "color: #2196F3;"
                  "}");

    button1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    button2->setSizePolicy(QSizePolicy::Expanding , QSizePolicy::Expanding);
    button3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    vLayout->addStretch();
    vLayout->addWidget(label);
    vLayout->setSpacing(20);
    vLayout->addWidget(button1);
    vLayout->setSpacing(20);
    vLayout->addWidget(button2);
    vLayout->setSpacing(20);
    vLayout->addWidget(button3);
    vLayout->addStretch();

    hLayout->addStretch();
    hLayout->addLayout(vLayout);
    hLayout->addStretch();



    connect(button1,&QPushButton::clicked,this,&Widget::withPlayer2Clicked);
    connect(button2,&QPushButton::clicked,this,&Widget::withComputerClicked);
    connect(button3,&QPushButton::clicked,this,&Widget::ChooseFieldSize);
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
    delete choose;
    delete game;
}

void Widget::withPlayer2Clicked()
{
    hide();
    if(game!=nullptr) delete game;
    game = new Game(nullptr,(choose->getSize() > 3) ? choose->getSize():3,0,this);
}

void Widget::ChooseFieldSize()
{
    hide();
    choose->show();
}

void Widget::withComputerClicked()
{
    hide();
    if(game!=nullptr) delete game;
     game = new Game(nullptr,(choose->getSize() > 3) ? choose->getSize():3,1,this);
}



