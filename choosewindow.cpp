
#include "choosewindow.h"

ChooseWindow::ChooseWindow(QWidget* mainMenu,QWidget * parent):QWidget(parent),mainMenu(mainMenu)
{
    setFixedSize(250,200);
    sizeOfField = 3;

    QLabel* label = new QLabel("Choose size of field");
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-family: Segoe Script; font-size: 16px; font-weight: bold;");

    QPushButton* ok = new QPushButton("OK");
    ok->setStyleSheet("QPushButton{background-color: #4CAF50; color: white; border-radius: 4px; font-size: 16px; padding: 8px 16px;}"
                      "QPushButton:pressed{ background-color: #2E8B57; }");

    QVBoxLayout* layout = new QVBoxLayout(this);
    line = new QLineEdit;
    line->setAlignment(Qt::AlignCenter);
    line->setText(QString::number(sizeOfField));
    line->setStyleSheet("border: 2px solid #ccc; font-size: 16px; padding: 8px;");

    layout->setDirection(QBoxLayout::TopToBottom);
    layout->setAlignment(Qt::AlignCenter);
    layout->setContentsMargins(30, 30, 30, 30);

    layout->addWidget(label);
    layout->addWidget(line);
    layout->addWidget(ok);
    connect(ok,&QPushButton::clicked,this,&ChooseWindow::OKclicked);
}

int ChooseWindow::getSize()
{
    return line->text().toInt();
}

void ChooseWindow::OKclicked()
{
    hide();
    mainMenu->show();
}

ChooseWindow::~ChooseWindow()
{
    delete line;
}


