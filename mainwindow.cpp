#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
extern QString filepath ;
extern std::vector<Counter> counters;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(300, 200);
    this->setWindowTitle("银行系统 · 登陆");
//    ui_mainMenu = new MainMenu();
    ui_register = new Register();

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
    pass->setEchoMode(QLineEdit::Password);

    label_user = new QLabel(this);
    label_user->setGeometry(40, 40, 60, 30);
    label_user->setText("用户名:");

    label_pass = new QLabel(this);
    label_pass->setGeometry(45, 85, 60, 30);
    label_pass->setText("密码:");

    QObject::connect(btn_login, SIGNAL(clicked()), this, SLOT(logIn()));
    QObject::connect(btn_reg, SIGNAL(clicked()), ui_register, SLOT(showUp()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::logIn(){
    QString username = user->text();
    QString password = pass->text();

    //登陆，待完善
    QString USERNAME;
    QString PASSWORD;
    QString NUMBER1;
    QString NUMBER2;
    QFile file(filepath+"/admin.txt");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        USERNAME = in.readLine();
        PASSWORD = in.readLine();
        NUMBER1 = in.readLine();
        NUMBER2 = in.readLine();
        norm_cnt=NUMBER1.toInt();
        spec_cnt=NUMBER2.toInt();
        counters.resize(norm_cnt+spec_cnt);

        if(username==USERNAME&&password==PASSWORD&&username.length()!=0&&password.length()!=0)
        {
             ui_mainMenu = new MainMenu();
             ui_mainMenu->show();
             this->close();
        }else{
            QMessageBox::critical(0 , "登陆失败" , "请检查用户名和密码!", QMessageBox::Ok | QMessageBox::Default , QMessageBox::Cancel | QMessageBox::Escape , 0);
        }

    }else{
        QMessageBox::critical(0 , "登陆失败" , "请先注册!", QMessageBox::Ok | QMessageBox::Default , QMessageBox::Cancel | QMessageBox::Escape , 0);
    }
    file.close();

    //如果成功登陆，则执行ui_mainMenu->show();显示主菜单窗口
    //并执行this->close();关闭登陆窗口。

}
