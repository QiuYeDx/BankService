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
