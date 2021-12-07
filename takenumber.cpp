#include "takenumber.h"
#include "ui_takenumber.h"

TakeNumber::TakeNumber(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TakeNumber)
{
    ui->setupUi(this);
    this->setFixedSize(380, 280);
    this->setWindowTitle("银行系统 · 取票");
    table = new QTableWidget(this);
    table->setColumnCount(3);
    table->setGeometry(40, 40, 300, 200);
    QStringList header;
    header<<tr("ID")<<tr("窗口")<<tr("status");
    table->setHorizontalHeaderLabels(header);
    //table->show();
}

TakeNumber::~TakeNumber()
{
    delete ui;
}
