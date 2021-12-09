#ifndef TAKENUMBER_H
#define TAKENUMBER_H

#include <QMainWindow>
#include <QPushButton>
#include <QTableWidget>
#include <QHeaderView>
#include <QDateTime>
namespace Ui {
class TakeNumber;
}

class TakeNumber : public QMainWindow
{
    Q_OBJECT
public slots:
    void getNormal();
    void getSpecial();
public:
    explicit TakeNumber(QWidget *parent = nullptr);
    ~TakeNumber();
    void putItem(QString ID, QString ID_Counter, QString Status);   //添加一行数据
    void popItem(int row);  //删除指定行数据 [0], [1], [2]...
    void setItem(int row, QString Status);  //修改指定行的Status数据
private:
    Ui::TakeNumber *ui;
    QPushButton *btn_normal, *btn_special;
    QTableWidget *table;
};

#endif // TAKENUMBER_H
