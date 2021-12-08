#include "mainwindow.h"
#include <QApplication>
#include <QDir>

#include"quene.h"
#include "counter.h"
#define QUENELENGTH 30
Quene quene_a(QUENELENGTH);
Quene quene_b(QUENELENGTH);
int client_number=0;
std::vector<Counter> counters(5);
QString filepath = QDir::currentPath();
int norm_cnt=0;//一般窗口
int spec_cnt=0;//特殊窗口

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    //qDebug() << "a" << endl;
    w.show();
    return a.exec();
}
