#include "takenumber.h"
#include "ui_takenumber.h"
#include "quene.h"
#include "user.h"
#include "counter.h"

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
    tmp_table = new QTableWidget(this);
    tmp_table->hide();
    table = new QTableWidget(this);
    table->setColumnCount(3);
    tmp_table->setColumnCount(3);
    table->setGeometry(40, 40, 300, 200);
    tmp_table->setGeometry(0, 00, 300, 200);
    QStringList header;
    header<<tr("ID")<<tr("窗口")<<tr("status");
    table->setHorizontalHeaderLabels(header);
    table->horizontalHeader()->setDefaultSectionSize(120); //设置默认表头宽度为120
    table->horizontalHeader()->resizeSection(0,30); //设置表头第一列的宽度为30
    table->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
    tmp_table->setHorizontalHeaderLabels(header);
    tmp_table->horizontalHeader()->setDefaultSectionSize(120); //设置默认表头宽度为120
    tmp_table->horizontalHeader()->resizeSection(0,30); //设置表头第一列的宽度为30
    tmp_table->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑

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
    quene_a.enQuene(++client_number,0);
    User *tmp = quene_a.findLastOne();
    if(tmp!=nullptr&&tmp->counter==-1)
    {
        if(getRowById(tmp->ID)!=-1)
            popItem(getRowById(tmp->ID));
        tmp->counter = calloc(tmp->type);//这个分配的窗口是从零开始的，是在显示的函数传值的时候才加的1
        putItem(QString::number(tmp->ID), tmp->counter==-1?"未分配":QString::number(tmp->counter+1), tmp->counter==-1?"排队中":(tmp->status==0?"请前往":"业务中"));
        if(tmp->counter!=-1)
        {
            User* t = quene_a.deQuene();//刚进去就被分配窗口的那个user理论上前面不会有人
            QDateTime tm_now=QDateTime::currentDateTime();
            t->tm_start=tm_now;
            counters[t->counter].user = t;
        }
    }
    Tablesort();
    //quene_a.output();
}

//特殊取号调用函数
void TakeNumber::getSpecial(){
    quene_b.enQuene(++client_number,1);
   // quene_b.output();
    User *tmp = quene_b.findLastOne();
    if(tmp!=nullptr&&tmp->counter==-1)
    {
        if(getRowById(tmp->ID)!=-1)
            popItem(getRowById(tmp->ID));
        tmp->counter = calloc(tmp->type);
        putItem(QString::number(tmp->ID), tmp->counter==-1?"未分配":QString::number(tmp->counter+1), tmp->counter==-1?"排队中":(tmp->status==0?"请前往":"业务中"));
        if(tmp->counter!=-1)
        {
            User* t = quene_b.deQuene();//刚进去就被分配窗口的那个user理论上前面不会有人
            QDateTime tm_now=QDateTime::currentDateTime();
            t->tm_start=tm_now;
            counters[t->counter].user = t;

        }
    }
    Tablesort();
    //quene_b.output();
}

//添加一行数据
void TakeNumber::putItem(QString ID, QString ID_Counter, QString Status){
    int row_count = table->rowCount(); //获取表单行数
    table->insertRow(row_count); //插入新行
    QTableWidgetItem *item_0 = new QTableWidgetItem();
    QTableWidgetItem *item_1 = new QTableWidgetItem();
    QTableWidgetItem *item_2 = new QTableWidgetItem();
    item_0->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    item_1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    item_2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    item_0->setText(ID);
    item_1->setText(ID_Counter);
    item_2->setText(Status);
    table->setItem(row_count, 0, item_0);
    table->setItem(row_count, 1, item_1);
    table->setItem(row_count, 2, item_2);
}

//添加一行数据
void TakeNumber::putItemTmp(QString ID, QString ID_Counter, QString Status){
    int row_count = tmp_table->rowCount(); //获取表单行数
    tmp_table->insertRow(row_count); //插入新行
    QTableWidgetItem *item_0 = new QTableWidgetItem();
    QTableWidgetItem *item_1 = new QTableWidgetItem();
    QTableWidgetItem *item_2 = new QTableWidgetItem();
    item_0->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    item_1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    item_2->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    item_0->setText(ID);
    item_1->setText(ID_Counter);
    item_2->setText(Status);
    tmp_table->setItem(row_count, 0, item_0);
    tmp_table->setItem(row_count, 1, item_1);
    tmp_table->setItem(row_count, 2, item_2);
}

//删除指定行的数据 [0], [1], [2]...
void TakeNumber::popItem(int row){
    table->removeRow(row);
}

//修改指定行的Status数据
void TakeNumber::setItem(int row, QString Status){
    QTableWidgetItem *item = new QTableWidgetItem();
    item->setText(Status);
    table->setItem(row, 2, item);
}

//通过ID获取行号,未找到返回-1
int TakeNumber::getRowById(int ID){
    for(int i=0;i<table->rowCount();i++){
        if(table->item(i, 0)->text().toInt() == ID)
            return i;
    }
    return -1;
}

//链表排序
void TakeNumber::Listsort(Node* &head){
    int i = 0;
    int j = 0;
    //用于变量链表
    Node * L = head;
    //作为一个临时量
    Node * p;
    Node * p1;
    //如果链表为空直接返回
    if (head->value == 0)return;

    for (i = 0; i < head->value - 1; i++) {
        L = head->next;
        for (j = 0; j < head->value - i - 1; j++) {
            //得到两个值
            p = L;
            p1 = L->next;
            //如果前面的那个比后面的那个大，就交换它们之间的是数据域
            if (p->value > p1->value) {
                int temp = p->value;
                int temp_index = p->index;
                p->value = p1->value;
                p->index = p1->index;
                p1->value = temp;
                p1->index = temp_index;
            }
            L = L->next;
        }
    }
}

//链表插入
void TakeNumber::ListInsert(Node* &head, int value, int index){
    Node *tmp;
    if(head->next != nullptr){
        tmp = head->next;
        while(tmp->next != nullptr){
            tmp = tmp->next;
        }
        tmp->next = new struct Node;
        tmp->next->value = value;
        tmp->next->index = index;
        tmp->next->next = nullptr;
        head->value++;
    }else{
        head->next = new struct Node;
        head->next->value = value;
        head->next->index = index;
        head->next->next = nullptr;
        head->value++;
    }
}

void TakeNumber::TableRe0(QTableWidget &table){
    int length = table.rowCount()-1;
    for(;length>=0;length--){
        table.removeRow(length);
    }
}

//Table排序
void TakeNumber::Tablesort(){
    int length = table->rowCount();
    Node *head = new struct Node;
    head->next = nullptr;
    head->value = 0;    //链表长度
    head->index = -1;
    for(int i=0;i<length;i++){
        ListInsert(head, table->item(i, 0)->text().toInt(), i);
        putItemTmp(table->item(i, 0)->text(), table->item(i, 1)->text(), table->item(i, 2)->text());
    }
    Listsort(head);
    TableRe0(*table);
    if(head->next != nullptr){
        head = head->next;
        while(head != nullptr){
            putItem(tmp_table->item(head->index, 0)->text(), tmp_table->item(head->index, 1)->text(), tmp_table->item(head->index, 2)->text());
            head = head->next;
        }
        TableRe0(*tmp_table);
    }
}
