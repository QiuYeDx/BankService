#include "takenumber.h"
#include "ui_takenumber.h"

TakeNumber::TakeNumber(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TakeNumber)
{
    ui->setupUi(this);
}

TakeNumber::~TakeNumber()
{
    delete ui;
}
