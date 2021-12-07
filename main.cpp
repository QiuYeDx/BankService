#include "mainwindow.h"
#include <QApplication>
#include"quene.h"
#define QUENELENGTH 30

Quene quene_a(QUENELENGTH);
Quene quene_b(QUENELENGTH);
int client_number=0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
