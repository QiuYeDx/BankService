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
    label_1->setGeometry(120, 5, 120, 30);
    label_1->setText("窗口号:");

    label_2 = new QLabel(this);
    label_2->setGeometry(180, 5, 120, 30);
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
    //group_1->setStyleSheet("border-radius: 7px;background-color:rgb(8,10,9)");

    group_2 = new QGroupBox(this);
    group_2->setGeometry(20,10,260,110);
    //group_2->setStyleSheet("border-radius: 7px;background-color:rgb(180,180,180)");


    label_info = new QLabel(this);
    label_info->setText("信息显示！！");
    label_info->setAlignment(Qt::AlignCenter);
    label_info->setGeometry(25,25,250,105);
    //label_info->hide();

    label_user = new QLabel(this);
    label_user->setGeometry(95, 135, 120, 30);
    label_user->setText("账户:");

    label_pwd = new QLabel(this);
    label_pwd->setGeometry(95, 175, 120, 30);
    label_pwd->setText("密码:");

    line_user =new QLineEdit(this);
    line_user->setGeometry(133, 135, 120, 30);

    line_pwd =new QLineEdit(this);
    line_pwd->setGeometry(133, 175, 120, 30);
    line_pwd->setEchoMode(QLineEdit::Password);

    label_money = new QLabel(this);
    label_money->setGeometry(95, 225, 40, 30);
    label_money->setText("金额:");
    label_money->hide();

    line_money =new QLineEdit(this);
    line_money->setGeometry(135, 225, 60, 30);
    //line_money->setEchoMode(QLineEdit::Password);
    line_money->hide();

    btn_4 = new QPushButton(this);
    btn_4->setGeometry(257, 170, 35, 40);
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
        label_user->setGeometry(70, 135, 120, 30);
        label_pwd->setGeometry(70, 175, 120, 30);
        line_user->setGeometry(110, 135, 120, 30);
        line_pwd->setGeometry(110, 175, 120, 30);
        btn_4->setGeometry(240, 170, 35, 40);
    }else{
        group_1->show();
        label_info->show();
        label_user->setGeometry(95, 135, 120, 30);
        label_pwd->setGeometry(95, 175, 120, 30);
        line_user->setGeometry(133, 135, 120, 30);
        line_pwd->setGeometry(133, 175, 120, 30);
        btn_4->setGeometry(257, 170, 35, 40);

    }
}

void StartService::login()
{
    QString username = line_user->text();
    QString password = line_pwd->text();

//    qDebug() << username << Qt::endl;
//    qDebug() << password << Qt::endl;
    if(type == 0)
    {
        qDebug()<<"type 0";
        if(ab.entry[username].password == password)
        {
            if(btn_1->isChecked()) //查询
            {
                QString t="";
                int k = ab.entry[username].container.size();
                auto tmp = ab.entry[username].container.end();
                if(k>3) k=3;
                for(int i = 0;i<k;i++)
                {
                    tmp--;
                    t += (tmp->time.toString()  + (tmp->type==1?" 存 ":" 取 ") + QString::number(tmp->amount) +"元\n");
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
            else //取款
            {
                float t = line_money->text().toFloat();
                int result = ab.entry[username].makeTrans(QDateTime::currentDateTime(),t,-1);
                if(result==0)
                    label_info->setText("成功取款 "+QString::number(t)+" 元");
                else
                    label_info->setText("请检查余额！！！");
            }
        }
        else
        {
            QMessageBox::critical(0 , "密码错误" , "请检查账户和密码!", QMessageBox::Ok | QMessageBox::Default , QMessageBox::Cancel | QMessageBox::Escape , 0);
        }

    }
    else
    {
        ab.addAccount(password, username);
        //label_info->setGeometry(120,60,120,30);
        label_info->setText("注册成功");
        setType(0);
    }
}


