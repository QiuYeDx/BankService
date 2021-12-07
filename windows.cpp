#include "windows.h"
#include "ui_windows.h"

Windows::Windows(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Windows)
{
    ui->setupUi(this);
    this->setWindowTitle("银行系统 · 窗口");
    this->setFixedSize(300, 300);
}

Windows::~Windows()
{
    delete ui;
}
