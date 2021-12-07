#include "storage.h"
#include "ui_storage.h"

Storage::Storage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Storage)
{
    ui->setupUi(this);
    this->setWindowTitle("银行系统 · 存储");
    this->setFixedSize(300, 300);
}

Storage::~Storage()
{
    delete ui;
}
