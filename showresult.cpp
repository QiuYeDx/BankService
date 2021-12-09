#include "showresult.h"
#include "ui_showresult.h"
#include "QDebug"

ShowResult::ShowResult(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShowResult)
{
    ui->setupUi(this);
    this->setWindowTitle("银行系统 · 统计");
    this->setFixedSize(300, 300);

    comboBox = new QComboBox(this);
    comboBox->setGeometry(50, 40,200, 30);
    comboBox->clear(); //清除列表

    comboBox->addItem("-------请选择日期-------");
    date_now=QDate::currentDate();
    for(int i=0;i>=-14;i--)
    {
        QString date = date_now.addDays(i).toString("      yyyy年MM月dd日");
        comboBox->addItem(date);
    }

    label_1 = new QLabel(this);
    label_1->setGeometry(60, 90, 120, 35);
    label_1->setText("一般业务\n      客户数量：");
    label_1->hide();

    label_2 = new QLabel(this);
    label_2->setGeometry(80, 130, 120, 35);
    label_2->setText("平均等待时间：\n平均业务时间：");
    label_2->hide();

    label_3 = new QLabel(this);
    label_3->setGeometry(60, 180, 120, 35);
    label_3->setText("特殊业务\n      客户数量：");
    label_3->hide();

    label_4 = new QLabel(this);
    label_4->setGeometry(80, 220, 120, 35);
    label_4->setText("平均等待时间：\n平均业务时间：");
    label_4->hide();

    label_5 = new QLabel(this);//一般客户数量
    label_5->setGeometry(145, 100, 120, 30);
    label_5->setText("0");
    label_5->hide();

    label_6 = new QLabel(this);
    label_6->setGeometry(170, 120, 120, 30);
    label_6->setText("0");
    label_6->hide();

    label_7 = new QLabel(this);
    label_7->setGeometry(170, 140, 120, 30);
    label_7->setText("0");
    label_7->hide();

    label_8 = new QLabel(this);//特殊客户数量
    label_8->setGeometry(145, 190, 120, 30);
    label_8->setText("0");
    label_8->hide();

    label_9 = new QLabel(this);
    label_9->setGeometry(170, 210, 120, 30);
    label_9->setText("0");
    label_9->hide();

    label_10 = new QLabel(this);
    label_10->setGeometry(170, 230, 120, 30);
    label_10->setText("0");
    label_10->hide();

    label_11 = new QLabel(this);
    label_11->setGeometry(110, 150, 120, 30);
    label_11->setText("无当日数据！");
    label_11->hide();

    QObject::connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateInformation(int)));
}

ShowResult::~ShowResult()
{
    delete ui;
}

void ShowResult::getResult(int index)
{
    num_a=0;
    num_b=0;
    int time_wait_a=0,time_wait_b=0,time_counter_a=0,time_counter_b=0;
    QFile file(filepath+"/result"+date_now.addDays(-1*index).toString("yyyyMMdd")+".txt");
   // qDebug()<<filepath+"/result"+date_now.addDays(-1*index).toString("yyyyMMdd")+".txt";
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString result;
        while(!in.atEnd())
        {
            result=in.readLine();
            QStringList list = result.split(" ");
            QString type = list[1];
            int tm_quene = (list[2].toInt()/10000)*3600 + ((list[2].toInt()/100)%100)*60 +list[2].toInt()%100;
            int tm_start= (list[3].toInt()/10000)*3600 + ((list[3].toInt()/100)%100)*60 +list[3].toInt()%100;
            int tm_end = (list[4].toInt()/10000)*3600 + ((list[4].toInt()/100)%100)*60 +list[4].toInt()%100;


            int tm_wait=tm_start-tm_quene;
            int tm_serve=tm_end-tm_start;

           if(type.toInt()==0)
           {
               num_a++;
               time_wait_a+=tm_wait;
               time_counter_a+=tm_serve;
           }
           else if(type.toInt()==1)
           {
               num_b++;
               time_wait_b+=tm_wait;
               time_counter_b+=tm_serve;
           }
        }
        if(num_a!=0)
        {
            int temp=time_wait_a/(num_a)*1.0;
            int hh=temp/3600;
            temp%=3600;
            int mm=temp/60;
            temp%=60;
            int ss=temp;
            time_wait_a_ave.setHMS(hh,mm,ss);
            temp=time_counter_a/(num_a)*1.0;
            hh=temp/3600;
            temp%=3600;
            mm=temp/60;
            temp%=60;
            ss=temp;
            time_serve_a_ave.setHMS(hh,mm,ss);
        }
        if(num_b!=0)
        {
            int temp=time_wait_b/(num_b)*1.0;
            int hh=temp/3600;
            temp%=3600;
            int mm=temp/60;
            temp%=60;
            int ss=temp;
            time_wait_b_ave.setHMS(hh,mm,ss);
            temp=time_counter_b/(num_b)*1.0;
            hh=temp/3600;
            temp%=3600;
            mm=temp/60;
            temp%=60;
            ss=temp;
            time_serve_b_ave.setHMS(hh,mm,ss);
        }
    }
    else{
        num_a=0;
        num_b=0;
    }
    file.close();
}

//更新信息
void ShowResult::updateInformation(int index){
   getResult(index-1);
   if(num_a==0&&num_b==0)
   {
        label_1->hide();
        label_2->hide();
        label_3->hide();
        label_4->hide();
        label_5->hide();
        label_6->hide();
        label_7->hide();
        label_8->hide();
        label_9->hide();
        label_10->hide();
        if(index==0)
            label_11->hide();
        else
            label_11->show();
   }else
   {
       if(num_a==0)
       {
           label_5->setText("0");
           label_1->show();
           label_5->show();
           label_11->hide();
       }
       else if(num_a!=0)
       {
           label_5->setText(QString::number(num_a));
            label_6->setText(time_wait_a_ave.toString("mm分ss秒"));
            label_7->setText(time_serve_a_ave.toString("mm分ss秒"));
            label_1->show();
            label_2->show();
            label_5->show();
            label_6->show();
            label_7->show();
            label_11->hide();
       }

       if(num_b==0)
       {
           label_8->setText("0");
           label_3->show();
           label_8->show();
           label_11->hide();
       }


       else if(num_b!=0)
       {
           label_8->setText(QString::number(num_b));
           label_9->setText(time_wait_b_ave.toString("mm分ss秒"));
           label_10->setText(time_serve_b_ave.toString("mm分ss秒"));
           label_3->show();
           label_4->show();
           label_8->show();
           label_9->show();
           label_10->show();
           label_11->hide();
       }
   }
}
