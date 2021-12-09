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
    label_1->setGeometry(80, 120, 120, 30);
    label_1->setText("窗口号:");

    label_2 = new QLabel(this);
    label_2->setGeometry(140, 120, 120, 30);
    label_2->setText(QString::number(ID));
}
