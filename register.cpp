#include "register.h"
#include "ui_register.h"
#include <QDebug>
#include <QDir>

//using namespace Qt;

Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    this->setFixedSize(300, 300);
    this->setWindowTitle("银行系统 · 注册");

    btn_reg = new QPushButton(this);
    btn_reg->setGeometry(110, 220, 80, 40);
    btn_reg->setText("注册");

    user = new QLineEdit(this);
    user->setGeometry(100, 40, 160, 30);

    pass = new QLineEdit(this);
    pass->setGeometry(100, 85, 160, 30);
    pass->setEchoMode(QLineEdit::PasswordEchoOnEdit);

    num = new QLineEdit(this);
    num->setGeometry(100, 130, 160, 30);

    num_2 = new QLineEdit(this);
    num_2->setGeometry(100, 175, 160, 30);

    label_user = new QLabel(this);
    label_user->setGeometry(40, 40, 60, 30);
    label_user->setText("用户名:");

    label_pass = new QLabel(this);
    label_pass->setGeometry(45, 85, 60, 30);
    label_pass->setText("密码:");

    label_num = new QLabel(this);
    label_num->setGeometry(25, 130, 80, 30);
    label_num->setText("一般窗口数:");

    label_num_2 = new QLabel(this);
    label_num_2->setGeometry(25, 175, 80, 30);
    label_num_2->setText("特殊窗口数:");

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
    QString number_2 = num_2->text();

    if(username.length()>0&&password.length()>0&&number.toInt()!=0&&number_2.toInt()!=0)//如果number输入的是字符串或者不输入转为int都为0
    {
        QFile file(filepath+"/admin.txt");
       // file.setFileName("admin.txt");
        if(file.open(QIODevice::WriteOnly|QIODevice::Text))
        {
            QTextStream in(&file);
            in<<username<<endl
             <<password<<endl
            <<number<<endl
           <<number_2<<endl;
        }
        file.close();
        this->close();
    }
}
