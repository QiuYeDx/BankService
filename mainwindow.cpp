#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(300, 200);
    this->setWindowTitle("银行系统 · 登陆");
    ui_mainMenu = new MainMenu();
    ui_mainMenu->setWindowTitle("银行系统 · 菜单");
    ui_mainMenu->setFixedSize(300, 300);

    btn_login = new QPushButton(this);
    btn_login->setGeometry(60, 140, 80, 40);
    btn_login->setText("登陆");

    btn_reg = new QPushButton(this);
    btn_reg->setGeometry(160, 140, 80, 40);
    btn_reg->setText("注册");

    user = new QLineEdit(this);
    user->setGeometry(100, 40, 160, 30);

    pass = new QLineEdit(this);
    pass->setGeometry(100, 85, 160, 30);

    label_user = new QLabel(this);
    label_user->setGeometry(40, 40, 60, 30);
    label_user->setText("用户名:");

    label_pass = new QLabel(this);
    label_pass->setGeometry(45, 85, 60, 30);
    label_pass->setText("密码:");

    QObject::connect(btn_login, SIGNAL(clicked()), ui_mainMenu, SLOT(showUp()));
    /*table_widget = new QTableWidget(this);
    table_widget->setColumnCount(4);
    table_widget->setGeometry(100, 100, 500, 250);
    QStringList header;
    header<<tr("name")<<tr("last modify time")<<tr("type")<<tr("size");
    table_widget->setHorizontalHeaderLabels(header);
    table_widget->show();*/

}

MainWindow::~MainWindow()
{
    delete ui;
}
