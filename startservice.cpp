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
    this->setFixedSize(320, 350);
    //this->setAttribute(Qt::WA_DeleteOnClose, true);

    label_1 = new QLabel(this);
    label_1->setGeometry(130,15, 120, 30);
    label_1->setText("窗口号:");

    label_2 = new QLabel(this);
    label_2->setGeometry(190, 15, 120, 30);
    label_2->setText(QString::number(ID));

    btn_1 = new QRadioButton(this);
    btn_1->setText("查询");

    btn_2 = new QRadioButton(this);
    btn_2->setText("存款");

    btn_3 = new QRadioButton(this);
    btn_3->setText("取款");

    layout_1 = new QVBoxLayout(this);
    layout_1->addWidget(btn_1);
    layout_1->addWidget(btn_2);
    layout_1->addWidget(btn_3);

    group_1 = new QGroupBox(this);
    group_1->setGeometry(13, 173, 75, 100);
    group_1->setLayout(layout_1);
    //group_1->setStyleSheet("border-radius: 7px;background-color:rgb(8,10,9)");

    group_2 = new QGroupBox(this);
    group_2->setGeometry(30,18,260,130);
    //group_2->setStyleSheet("border-radius: 7px;background-color:rgb(180,180,180)");

    label_info = new QLabel(this);
    label_info->setText("信息显示！！");
    label_info->setAlignment(Qt::AlignCenter);
    label_info->setGeometry(35,45,250,110);
    //label_info->hide();

    label_user = new QLabel(this);
    //label_user->setGeometry(95, 175, 120, 30);
    label_user->setText("账户:");

    label_pwd = new QLabel(this);
   // label_pwd->setGeometry(95, 215, 120, 30);
    label_pwd->setText("密码:");

    line_user =new QLineEdit(this);
   // line_user->setGeometry(133, 175, 120, 30);

    line_pwd =new QLineEdit(this);
   // line_pwd->setGeometry(133, 215, 120, 30);
    line_pwd->setEchoMode(QLineEdit::Password);

    label_money = new QLabel(this);
    label_money->setGeometry(100, 275, 40, 30);
    label_money->setText("金额:");
    label_money->hide();

    line_money =new QLineEdit(this);
    line_money->setGeometry(140, 275, 60, 30);
    //line_money->setEchoMode(QLineEdit::Password);
    line_money->hide();

    btn_4 = new QPushButton(this);
    btn_4->setGeometry(257, 210, 35, 40);
    btn_4->setText("√");

    QObject::connect(btn_1,SIGNAL(toggled(bool)),this,SLOT(chooseServiceType()));
    QObject::connect(btn_2,SIGNAL(toggled(bool)),this,SLOT(chooseServiceType()));
    QObject::connect(btn_3,SIGNAL(toggled(bool)),this,SLOT(chooseServiceType()));
    QObject::connect(btn_4,SIGNAL(clicked()),this,SLOT(login()));
}

void StartService::chooseServiceType()
{
    if(btn_1->isChecked()){
        label_money->hide();
        line_money->hide();
    }
    if(btn_2->isChecked()){
        label_money->show();
        line_money->show();
    }
    if(btn_3->isChecked()){
        label_money->show();
        line_money->show();
    }
}

void StartService::setType(int index)
{
    type=index;
    qDebug()<<index;
    if(type==1)
    {
        group_1->hide();
        label_info->setText("开户");
        label_info->show();
        label_user->setGeometry(75, 180, 120, 30);
        label_pwd->setGeometry(75, 230, 120, 30);
        line_user->setGeometry(115, 180, 120, 30);
        line_pwd->setGeometry(115, 230, 120, 30);
        btn_4->setGeometry(240, 225, 35, 40);
    }else{
        group_1->show();
        label_info->show();
        label_user->setGeometry(100, 180, 120, 30);
        label_pwd->setGeometry(100, 230, 120, 30);
        line_user->setGeometry(140, 180, 120, 30);
        line_pwd->setGeometry(140, 230, 120, 30);
        btn_4->setGeometry(265, 225, 35, 40);

    }
}

void StartService::login()
{
    QString username = line_user->text();
    QString password = line_pwd->text();

    line_user->setEnabled(false);
    line_pwd->setEnabled(false);

    if(type == 0)
    {
        qDebug()<<"type 0";
        if(ab.entry[username].password == password)
        {
            if(btn_1->isChecked()) //查询
            {
                QString t="";
                int k = ab.entry[username].container.size();
                if(k>3) k=3;
                for(int i = 0;i<k;i++)
                {
                    t += (ab.entry[username].container[i].time.toString()  + (ab.entry[username].container[i].type==1?" 存 ":" 取 ") + QString::number(ab.entry[username].container[i].amount) +"元\n");
                }
                //label_info->setGeometry(120,60,120,120);
                qDebug()<<QString::number(ab.entry[username].Balance);
                label_info->setText("余额 "+QString::number(ab.entry[username].Balance)+ "\n近三次交易记录:" + "\n" + t);
            }
            else if(btn_2->isChecked()) //存款
            {
                float t = line_money->text().toFloat();
                int result = ab.entry[username].makeTrans(QDateTime::currentDateTime(),t,1);
                //label_info->setGeometry(120,60,300,30);
                if(result==0)
                    label_info->setText("成功存款 "+QString::number(t)+" 元");

            }
            else if(btn_3->isChecked())//取款
            {
                float t = line_money->text().toFloat();
                int result = ab.entry[username].makeTrans(QDateTime::currentDateTime(),t,-1);
                if(result==0)
                    label_info->setText("成功取款 "+QString::number(t)+" 元");
                else
                    label_info->setText("余额不足，请检查余额！！！");
            }
            else
            {
                label_info->setText("登陆成功");
            }
        }
        else
        {
            QMessageBox::critical(0 , "密码错误" , "请检查账户和密码!", QMessageBox::Ok | QMessageBox::Default , QMessageBox::Cancel | QMessageBox::Escape , 0);
            line_user->setEnabled(true);
            line_pwd->setEnabled(true);
        }

    }
    else
    {
        ab.addAccount(password, username);
        //label_info->setGeometry(120,60,120,30);
        label_info->setText("注册成功");
        setType(0);
        line_user->setEnabled(false);
        line_pwd->setEnabled(false);
    }
}


