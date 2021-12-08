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
}

ShowResult::~ShowResult()
{
    delete ui;
}

void ShowResult::getResult()
{
    int num_a=0,num_b=0;
    int time_wait_a=0,time_wait_b=0,time_counter_a=0,time_counter_b=0;
    QDate date=QDate::currentDate();
    QFile file(filepath+"/result"+date.toString("yyyymmdd")+".txt");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString result;
        while(!in.atEnd())
        {
            result=in.readLine();
            QStringList list = result.split(" ");
            QString type = list[1];
            QString tm_quene = list[2];
            QString tm_start= list[3];
            QString tm_end = list[4];
            int tm_wait=(tm_start.toInt()/10000-tm_quene.toInt()/10000)*60+((tm_start.toInt()%10000-tm_quene.toInt()%10000))/100;
            int tm_serve=(tm_end.toInt()/10000-tm_start.toInt()/10000)*60+((tm_end.toInt()%10000-tm_start.toInt()%10000))/100;
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
        float time_wait_a_ave;
        float time_wait_b_ave;
        float time_serve_a_ave;
        float time_serve_b_ave;


        if(num_a!=0)
        {
             time_wait_a_ave=time_wait_a/(num_a)*1.0;
           time_serve_a_ave=time_counter_a/num_a*1.0;
        }
        if(num_b!=0)
        {
           time_wait_b_ave=time_wait_b/(num_b)*1.0;
           time_serve_b_ave=time_counter_b/num_b*1.0;
        }
       // qDebug()<<time_wait_ave<<" "<<time_serve_a_ave<<" "<<time_serve_b_ave<<Qt::endl;
            //对字符串的处理

        QString showres="";
        if(num_a!=0)
            showres+="一般业务顾客："+QString::number(num_a)+"\n排队时间"+QString::number(time_wait_a_ave)+"\n业务时间"+QString::number(time_serve_a_ave);
        if(num_b!=0)
            showres+="teshu业务顾客："+QString::number(num_a)+"\n排队时间"+QString::number(time_wait_b_ave)+"\n业务时间"+QString::number(time_serve_b_ave);

        //用于临时输出
        label = new QLabel(this);
        label->setGeometry(30, 30, 120, 120);
        label->setText(showres);

    }
    file.close();
}
