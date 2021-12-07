#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    this->setWindowTitle("银行系统 · 菜单");
    this->setFixedSize(300, 300);
    ui_takeNumber = new TakeNumber();
    ui_windows = new Windows();
    ui_showResult = new ShowResult();
    ui_storage = new Storage();

    btn_1 = new QPushButton(this);
    btn_1->setGeometry(60, 40, 180, 40);
    btn_1->setText("取号");

    btn_2 = new QPushButton(this);
    btn_2->setGeometry(60, 100, 180, 40);
    btn_2->setText("窗口");

    btn_3 = new QPushButton(this);
    btn_3->setGeometry(60, 160, 180, 40);
    btn_3->setText("统计");

    btn_4 = new QPushButton(this);
    btn_4->setGeometry(60, 220, 180, 40);
    btn_4->setText("存储");

    QObject::connect(btn_1, SIGNAL(clicked()), this, SLOT(showQuHao()));
    QObject::connect(btn_2, SIGNAL(clicked()), this, SLOT(showChuangKou()));
    QObject::connect(btn_3, SIGNAL(clicked()), this, SLOT(showZhanShi()));
    QObject::connect(btn_4, SIGNAL(clicked()), this, SLOT(showCunChu()));
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::showUp(){
    this->show();
}

void MainMenu::showQuHao(){
    ui_takeNumber->show();
}

void MainMenu::showChuangKou(){
    ui_windows->show();
}

void MainMenu::showZhanShi(){
    ui_showResult->show();
}

void MainMenu::showCunChu(){
    ui_storage->show();
}
