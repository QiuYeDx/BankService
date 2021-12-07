#include "mainwindow.h"
#include <QApplication>
#include"quene.h"
#include "counter.h"
#define QUENELENGTH 30
#define NORMCNT 8
#define SPECCNT 4
Quene quene_a(QUENELENGTH);
Quene quene_b(QUENELENGTH);
int client_number=0;
Counter counters[NORMCNT+SPECCNT];

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
