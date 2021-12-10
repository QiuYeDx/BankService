#include "mainwindow.h"
#include <QApplication>
#include <QDir>
#include "accountbook.h"
#include"quene.h"
#include "counter.h"

Quene quene_a;
Quene quene_b;
int client_number=0;
std::vector<Counter> counters(5);
QString filepath = QDir::currentPath();
int norm_cnt=0;//一般窗口
int spec_cnt=0;//特殊窗口
AccountBook ab;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    //qDebug() << "a" << endl;
    w.show();
    return a.exec();
}
