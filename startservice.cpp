#include "startservice.h"
#include "ui_startservice.h"

StartService::StartService(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartService)
{
    ui->setupUi(this);
}

StartService::~StartService()
{
    delete ui;
}

StartService::StartService(int ID):
    ID(ID)
{
    this->setWindowTitle("银行系统 · 业务");
    this->setFixedSize(300, 300);
    //this->setAttribute(Qt::WA_DeleteOnClose, true);

    label_1 = new QLabel(this);
    label_1->setGeometry(80, 20, 120, 30);
    label_1->setText("窗口号:");

    label_2 = new QLabel(this);
    label_2->setGeometry(140, 20, 120, 30);
    label_2->setText(QString::number(ID));

    btn_1 = new QRadioButton(this);
   // btn_1->setGeometry(25,120,100,40);
    btn_1->setText("查询");

    btn_2 = new QRadioButton(this);
   // btn_2->setGeometry(25,150,100,40);
    btn_2->setText("存款");

    btn_3 = new QRadioButton(this);
    //btn_3->setGeometry(25,180,100,40);
    btn_3->setText("取款");

    layout_1 = new QVBoxLayout(this);
    layout_1->addWidget(btn_1);
    layout_1->addWidget(btn_2);
    layout_1->addWidget(btn_3);

    group_1 = new QGroupBox(this);
    group_1->setGeometry(10, 125, 75, 90);
    group_1->setLayout(layout_1);

    label_info = new QLabel(this);
    label_info->setGeometry(35, 50, 120, 30);
    label_info->setText("信息显示！！");

    label_user = new QLabel(this);
    label_user->setGeometry(95, 135, 120, 30);
    label_user->setText("账户:");

    label_pwd = new QLabel(this);
    label_pwd->setGeometry(95, 175, 120, 30);
    label_pwd->setText("密码:");

    line_user =new QLineEdit(this);
    line_user->setGeometry(135, 135, 120, 30);

    line_pwd =new QLineEdit(this);
    line_pwd->setGeometry(135, 175, 120, 30);
    line_pwd->setEchoMode(QLineEdit::Password);

    label_money = new QLabel(this);
    label_money->setGeometry(95, 225, 40, 30);
    label_money->setText("金额:");

    line_money =new QLineEdit(this);
    line_money->setGeometry(135, 225, 60, 30);
    line_money->setEchoMode(QLineEdit::Password);


    btn_4 = new QPushButton(this);
    btn_4->setGeometry(260, 170, 40, 40);
    btn_4->setText("√");



//    layout_2 = new QVBoxLayout(this);
//    layout_2->addWidget(label_user);
//    layout_2->addWidget(label_pwd);
//    layout_2->addWidget(line_user);
//    layout_2->addWidget(line_pwd);


}
