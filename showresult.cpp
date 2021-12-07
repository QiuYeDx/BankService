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
