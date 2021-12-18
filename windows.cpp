#include "windows.h"
#include "ui_windows.h"
#include "counter.h"

using namespace Qt;

Windows::Windows(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Windows)
{
    ui->setupUi(this);
    this->setWindowTitle("银行系统 · 窗口");
    this->setFixedSize(300, 300);
    ui_service = new StartService();
    ui_service->setWindowTitle("银行系统 · 业务");
    ui_service->setFixedSize(300, 300);


    btn_switch = new QPushButton(this);
    btn_switch->setGeometry(90, 240, 120, 40);
    btn_switch->setText("开始业务");

    comboBox = new QComboBox(this);
    comboBox->setGeometry(40, 40, 220, 30);
    comboBox->clear(); //清除列表
    for (int i=1;i<=norm_cnt;i++)
    {
        comboBox->addItem(QString::asprintf(">>「一般窗口」---%d号窗口<<",i));
    }
    for (int i=norm_cnt+1;i<=norm_cnt+spec_cnt;i++)
        comboBox->addItem(QString::asprintf(">>「特殊窗口」---%d号窗口<<",i));

    label_1 = new QLabel(this);
    label_1->setGeometry(80, 120, 120, 30);
    label_1->setText("窗口号:");

    label_2 = new QLabel(this);
    label_2->setGeometry(140, 120, 120, 30);
    label_2->setText("1");

    label_3 = new QLabel(this);
    label_3->setGeometry(80, 180, 120, 30);
    label_3->setText("窗口状态:");

    label_4 = new QLabel(this);
    label_4->setGeometry(140, 180, 120, 30);
    label_4->setText(counters[0].occupied?"业务办理中...":"空闲中...");

    label_5 = new QLabel(this);
    label_5->setGeometry(80, 150, 120, 30);
    label_5->setText("ID:");

    label_6 = new QLabel(this);
    label_6->setGeometry(140, 150, 120, 30);
    label_6->setText(counters[0].user==nullptr?"---":QString::number(counters[0].user->ID));

    QObject::connect(btn_switch, SIGNAL(clicked()), this, SLOT(Service()));
    QObject::connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateInformation(int)));
}

Windows::~Windows()
{
    delete ui;
}

//业务函数
void Windows::Service(){
    if(btn_switch->text() == "开始业务"){
        //开始业务
        if(counters[(label_2->text()).toInt()-1].user!=nullptr){
            if( counters[(label_2->text()).toInt()-1].user->status == 0 && ui_takeNumber_ptr->getRowById(counters[(label_2->text()).toInt()-1].user->ID)!=-1){
                ui_takeNumber_ptr->popItem(ui_takeNumber_ptr->getRowById(counters[(label_2->text()).toInt()-1].user->ID));
                counters[(label_2->text()).toInt()-1].user->status = 1;
                ui_takeNumber_ptr->putItem(QString::number(counters[(label_2->text()).toInt()-1].user->ID), counters[(label_2->text()).toInt()-1].user->counter==-1?"未分配":QString::number(counters[(label_2->text()).toInt()-1].user->counter+1), counters[(label_2->text()).toInt()-1].user->counter==-1?"排队中":(counters[(label_2->text()).toInt()-1].user->status==0?"请前往":"业务中"));
            }
            counters[(label_2->text()).toInt()-1].occupied = true;
            counters[(label_2->text()).toInt()-1].user->status = 1;
            updateInformation((label_2->text()).toInt()-1);
            ui_service = new StartService(label_2->text().toInt());
            ui_service->setType(counters[(label_2->text()).toInt()-1].user->type);
            ui_service->show();
            ui_takeNumber_ptr->Tablesort();
            //showService();
            //btn_switch->setText("结束业务");
            //label_4->setText("业务办理中...");
        }else
            QMessageBox::critical(0 , "业务警告" , "当前窗口无待处理业务", QMessageBox::Ok | QMessageBox::Default , QMessageBox::Cancel | QMessageBox::Escape , 0);
        //待完善
    }else{
        //结束业务
        counters[(label_2->text()).toInt()-1].user->tm_end = QDateTime::currentDateTime();
        //user内容存盘
        qDebug()<<"开始写文件";

        QDate date=QDate::currentDate();
        QFile file(filepath+"/result"+date.toString("yyyyMMdd")+".txt");
        if(file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append))
        {
            QTextStream in(&file);
            in<<counters[(label_2->text()).toInt()-1].user->ID<<" "
               <<counters[(label_2->text()).toInt()-1].user->type<<" "
              <<counters[(label_2->text()).toInt()-1].user->tm_quene.toString("hhmmss")<<" "
             <<counters[(label_2->text()).toInt()-1].user->tm_start.toString("hhmmss")<<" "
            <<counters[(label_2->text()).toInt()-1].user->tm_end.toString("hhmmss")<<endl;
        }
        file.close();
        qDebug()<<"成功写文件";
        ui_takeNumber_ptr->popItem(ui_takeNumber_ptr->getRowById(counters[(label_2->text()).toInt()-1].user->ID));
        delete(counters[(label_2->text()).toInt()-1].user);
        counters[(label_2->text()).toInt()-1].user=nullptr;
        counters[(label_2->text()).toInt()-1].occupied=false;
        counters[(label_2->text()).toInt()-1].allocated=false;

        //为新用户开个窗口
        User *tmp = quene_a.getFirstWaiting();
        if(tmp!=nullptr&&tmp->counter==-1)
        {
            if(ui_takeNumber_ptr->getRowById(tmp->ID)!=-1)
                ui_takeNumber_ptr->popItem(ui_takeNumber_ptr->getRowById(tmp->ID));
            tmp->counter = calloc(tmp->type);//这个分配的窗口是从零开始的，是在显示的函数传值的时候才加的1
            ui_takeNumber_ptr->putItem(QString::number(tmp->ID), tmp->counter==-1?"未分配":QString::number(tmp->counter+1), tmp->counter==-1?"排队中":(tmp->status==0?"请前往":"业务中"));
            if(tmp->counter!=-1)
            {
                User* t = quene_a.deQuene();//刚进去就被分配窗口的那个user理论上前面不会有人
                QDateTime tm_now=QDateTime::currentDateTime();
                t->tm_start=tm_now;

                counters[t->counter].user = t;
            }
        }

        tmp = quene_b.getFirstWaiting();
        if(tmp!=nullptr&&tmp->counter==-1)
        {
            if(ui_takeNumber_ptr->getRowById(tmp->ID)!=-1)
                ui_takeNumber_ptr->popItem(ui_takeNumber_ptr->getRowById(tmp->ID));
            tmp->counter = calloc(tmp->type);
            ui_takeNumber_ptr->putItem(QString::number(tmp->ID), tmp->counter==-1?"未分配":QString::number(tmp->counter+1), tmp->counter==-1?"排队中":(tmp->status==0?"请前往":"业务中"));

            if(tmp->counter!=-1)
            {
                User* t = quene_b.deQuene();//刚进去就被分配窗口的那个user理论上前面不会有人
                QDateTime tm_now=QDateTime::currentDateTime();
                t->tm_start=tm_now;
                counters[t->counter].user = t;
            }
        }

        updateInformation(label_2->text().toInt()-1);
        ui_takeNumber_ptr->Tablesort();
    }
}

//更新信息
void Windows::updateInformation(int index){
    label_2->setText(QString::number(index+1));
    label_4->setText(counters[index].occupied?"业务办理中...":"空闲中...");
    label_6->setText(counters[index].user==nullptr?"---":QString::number(counters[index].user->ID));
    if(counters[index].occupied)
        btn_switch->setText("结束业务");
    else
        btn_switch->setText("开始业务");
}

void Windows::showService(){
    ui_service->setType(counters[(label_2->text()).toInt()-1].user->type);
    qDebug()<<counters[(label_2->text()).toInt()-1].user->type;
    ui_service->show();
}

void Windows::getTakeNumberPtr(TakeNumber *ptr){
    this->ui_takeNumber_ptr = ptr;
}
