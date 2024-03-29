#ifndef TAKENUMBER_H
#define TAKENUMBER_H

#include <QMainWindow>
#include <QPushButton>
#include <QTableWidget>
#include <QHeaderView>
#include <QDateTime>

typedef struct Node{
    int value, index;   //value == ID
    struct Node *next;
}Node;

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
    void putItemTmp(QString ID, QString ID_Counter, QString Status);
    void popItem(int row);  //删除指定行数据 [0], [1], [2]...
    void setItem(int row, QString Status);  //修改指定行的Status数据
    int getRowById(int ID); //通过ID获取行号,未找到返回-1
    void Listsort(Node* &head);
    void ListInsert(Node* &head, int value, int index);
    void Tablesort();
    void TableRe0(QTableWidget &table);
private:
    Ui::TakeNumber *ui;
    QPushButton *btn_normal, *btn_special;
    QTableWidget *table, *tmp_table;
};

#endif // TAKENUMBER_H
