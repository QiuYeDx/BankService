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
    label_1->setGeometry(120, 25, 120, 30);
    label_1->setText("窗口号:");

    label_2 = new QLabel(this);
    label_2->setGeometry(180, 25, 120, 30);
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

    group_2 = new QGroupBox(this);
    group_2->setGeometry(40,25,220,80);


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
    label_money->hide();

    line_money =new QLineEdit(this);
    line_money->setGeometry(135, 225, 60, 30);
    line_money->setEchoMode(QLineEdit::Password);
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
    }else{
        group_1->show();
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
        if(ab.entry[username].password == password)
        {
            if(btn_1->isChecked()) //查询
            {
                QString t="";
                int k = ab.entry[username].container.size();
                for(int i = 0;i<k;i++)
                {
                    t += ("时间 "+ab.entry[username].container[i].time.toString() + "金额 " +QString::number(ab.entry[username].container[i].amount)  + "类型 "+(type==1?"存":"取")+"\n");
                }
                label_info->setText("余额"+QString::number(ab.entry[username].Balance)+ "\n近三次交易记录:" + "\n" + t);
            }
            else if(btn_2->isChecked()) //存款
            {
                float t = line_money->text().toFloat();
                ab.entry[username].makeTrans(QDateTime::currentDateTime(),t,1);

            }
            else //取款
            {
                float t = line_money->text().toFloat();
                ab.entry[username].makeTrans(QDateTime::currentDateTime(),t,-1);
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
        label_info->setText("注册成功");
    }
}


