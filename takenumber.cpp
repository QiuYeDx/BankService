#include "takenumber.h"
#include "ui_takenumber.h"
#include"quene.h"

extern Quene quene_a;
extern Quene quene_b;
extern int client_number;

TakeNumber::TakeNumber(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TakeNumber)
{
    ui->setupUi(this);
    this->setFixedSize(380, 320);
    this->setWindowTitle("银行系统 · 取票");
    table = new QTableWidget(this);
    table->setColumnCount(3);
    table->setGeometry(40, 40, 300, 200);
    QStringList header;
    header<<tr("ID")<<tr("窗口")<<tr("status");
    table->setHorizontalHeaderLabels(header);

    table->horizontalHeader()->setDefaultSectionSize(120); //设置默认表头宽度为120
    table->horizontalHeader()->resizeSection(0,30); //设置表头第一列的宽度为30
    table->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑

    btn_normal = new QPushButton(this);
    btn_normal->setGeometry(50, 260, 120, 40);
    btn_normal->setText("一般取号");

    btn_special = new QPushButton(this);
    btn_special->setGeometry(210, 260, 120, 40);
    btn_special->setText("特殊取号");

    QObject::connect(btn_normal, SIGNAL(clicked()), this, SLOT(getNormal()));
    QObject::connect(btn_special, SIGNAL(clicked()), this, SLOT(getSpecial()));
}

TakeNumber::~TakeNumber()
{
    delete ui;
}

//一般取号调用函数
void TakeNumber::getNormal(){
    quene_a.push(++client_number,1);
    //todo加个calloc
    //quene_a.output();
}

//特殊取号调用函数
void TakeNumber::getSpecial(){
    quene_b.push(++client_number,2);
    //todo加个calloc
    //quene_b.output();
}

//添加一行数据
void TakeNumber::putItem(QString ID, QString ID_Counter, QString Status){
    int row_count = table->rowCount(); //获取表单行数
    table->insertRow(row_count); //插入新行
    QTableWidgetItem *item_0 = new QTableWidgetItem();
    QTableWidgetItem *item_1 = new QTableWidgetItem();
    QTableWidgetItem *item_2 = new QTableWidgetItem();
    item_0->setText(ID);
    item_1->setText(ID_Counter);
    item_2->setText(Status);
    table->setItem(row_count, 0, item_0);
    table->setItem(row_count, 1, item_1);
    table->setItem(row_count, 2, item_2);
}

//删除指定行数据 [0], [1], [2]...
void TakeNumber::popItem(int row){
    table->removeRow(row);
}

//修改指定行的Status数据
void TakeNumber::setItem(int row, QString Status){
    QTableWidgetItem *item = new QTableWidgetItem();
    item->setText(Status);
    table->setItem(row, 2, item);
}
