#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    btn_1 = new QPushButton(this);
    btn_1->setGeometry(60, 40, 180, 40);
    btn_1->setText("取号");

    btn_2 = new QPushButton(this);
    btn_2->setGeometry(60, 100, 180, 40);
    btn_2->setText("窗口");

    btn_3 = new QPushButton(this);
    btn_3->setGeometry(60, 160, 180, 40);
    btn_3->setText("展示");

    btn_4 = new QPushButton(this);
    btn_4->setGeometry(60, 220, 180, 40);
    btn_4->setText("存储");
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::showUp(){
    this->show();
}
