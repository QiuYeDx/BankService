#include "windows.h"
#include "ui_windows.h"
#include "counter.h"
#define NORMCNT 8
#define SPECCNT 4
extern Counter counters[NORMCNT+SPECCNT];
Windows::Windows(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Windows)
{
    ui->setupUi(this);
    this->setWindowTitle("银行系统 · 窗口");
    this->setFixedSize(300, 300);

    btn_switch = new QPushButton(this);
    btn_switch->setGeometry(90, 240, 120, 40);
    btn_switch->setText("开始");

    comboBox = new QComboBox(this);
    comboBox->setGeometry(40, 40, 220, 30);
    comboBox->clear(); //清除列表
    for (int i=1;i<=8;i++)
        comboBox->addItem(QString::asprintf(">>「一般窗口」---%d号窗口<<",i));
    for (int i=9;i<=13;i++)
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

    QObject::connect(btn_switch, SIGNAL(clicked()), this, SLOT(Service()));
    QObject::connect(btn_switch, SIGNAL(clicked()), this, SLOT(updateInformation(int)));
    QObject::connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateInformation(int)));
}

Windows::~Windows()
{
    delete ui;
}

//结束函数
void Windows::Service(){
    if(btn_switch->text() == "开始业务"){
        btn_switch->setText("结束业务");
        counters[label_2->text().toInt()].occupied = true;

    }else{

    }
}

//更新信息
void Windows::updateInformation(int index){
    label_2->setText(QString::number(index+1));
    label_4->setText(counters[index].occupied?"业务办理中...":"空闲中...");
    if(counters[index].occupied)
        btn_switch->setText("结束业务");
    else
        btn_switch->setText("开始业务");
}
