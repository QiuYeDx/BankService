#include "takenumber.h"
#include "ui_takenumber.h"

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

    btn_normal = new QPushButton(this);
    btn_normal->setGeometry(50, 260, 120, 40);
    btn_normal->setText("一般取号");

    btn_special = new QPushButton(this);
    btn_special->setGeometry(210, 260, 120, 40);
    btn_special->setText("特殊取号");

    QObject::connect(btn_normal, SIGNAL(clicked()), this, SLOT(getNormal()));
    QObject::connect(btn_normal, SIGNAL(clicked()), this, SLOT(getSpecial()));
}

TakeNumber::~TakeNumber()
{
    delete ui;
}

//一般取号调用函数
void TakeNumber::getNormal(){

}

//特殊取号调用函数
void TakeNumber::getSpecial(){

}
