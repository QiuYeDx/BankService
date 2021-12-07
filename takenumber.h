#ifndef TAKENUMBER_H
#define TAKENUMBER_H

#include <QMainWindow>
#include <QPushButton>
#include <QTableWidget>
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

private:
    Ui::TakeNumber *ui;
    QPushButton *btn_normal, *btn_special;
    QTableWidget *table;
};

#endif // TAKENUMBER_H
