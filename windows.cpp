#include "windows.h"
#include "ui_windows.h"

Windows::Windows(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Windows)
{
    ui->setupUi(this);
    this->setWindowTitle("银行系统 · 窗口");
    this->setFixedSize(300, 300);

    btn_switch = new QPushButton(this);
    btn_switch->setGeometry(90, 240, 120, 40);
    btn_switch->setText("开始");

    comboBox = new QComboBox(this);
    comboBox->setGeometry(40, 40, 220, 30);
    comboBox->clear(); //清除列表
    for (int i=1;i<=8;i++)
        comboBox->addItem(QString::asprintf(">>「一般窗口」---%d号窗口<<",i));
    for (int i=9;i<=13;i++)
        comboBox->addItem(QString::asprintf(">>「特殊窗口」---%d号窗口<<",i));
}

Windows::~Windows()
{
    delete ui;
}
