#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    this->setFixedSize(300, 250);
    this->setWindowTitle("银行系统 · 注册");

    btn_reg = new QPushButton(this);
    btn_reg->setGeometry(110, 140, 80, 40);
    btn_reg->setText("注册");

    user = new QLineEdit(this);
    user->setGeometry(100, 40, 160, 30);

    pass = new QLineEdit(this);
    pass->setGeometry(100, 85, 160, 30);

    num = new QLineEdit(this);
    num->setGeometry(100, 130, 160, 30);

    label_user = new QLabel(this);
    label_user->setGeometry(40, 40, 60, 30);
    label_user->setText("用户名:");

    label_pass = new QLabel(this);
    label_pass->setGeometry(45, 85, 60, 30);
    label_pass->setText("密码:");

    label_num = new QLabel(this);
    label_num->setGeometry(40, 130, 60, 30);
    label_num->setText("窗口数:");

    QObject::connect(btn_reg, SIGNAL(clicked()), this, SLOT(regist()));
}

Register::~Register()
{
    delete ui;
}

void Register::showUp(){
    this->show();
}

void Register::regist(){
    //注册
    //待完善
    QString username = user->text();
    QString password = pass->text();
    QString number = num->text();
}
