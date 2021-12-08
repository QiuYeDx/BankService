#include "showresult.h"
#include "ui_showresult.h"

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
    int time_wait=0,time_counter_0,time_counter_b=0;
    QDate date=QDate::currentDate();
    QFile file(filepath+"/result"+date.toString("yyyymmdd")+".txt");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString result;
        while(!in.atEnd())
        {
            QStringList list = result.split(" ");
            QString id = list[0];
            QString type = list[1];
            QString tm_quene = list[2];
            QString tm_start= list[3];
            QString tm_end = list[4];
           // if(type.toInt()==0)

               //对字符串的处理
        }

    }
    file.close();
}
