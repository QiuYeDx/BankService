#ifndef SHOWRESULT_H
#define SHOWRESULT_H

#include <QMainWindow>
#include <QLabel>
#include <QFile>
#include <QDate>
#include <QTextStream>
#include <QComboBox>

extern QString filepath;

namespace Ui {
class ShowResult;
}

class ShowResult : public QMainWindow
{
    Q_OBJECT
public slots:
    void updateInformation(int index);
public:
    explicit ShowResult(QWidget *parent = nullptr);
    ~ShowResult();
    void getResult(int index);

private:
    Ui::ShowResult *ui;
    QLabel *label;
    QLabel *label_1,*label_2,*label_3,*label_4,*label_5,*label_6,*label_7,
    *label_8,*label_9,*label_10,*label_11,*label_12,*label_13,*label_14,*label_15;
    QComboBox *comboBox;
    QDate date_now;
    float time_wait_a_ave;
    float time_wait_b_ave;
    float time_serve_a_ave;
    float time_serve_b_ave;
    int  num_a,num_b;

};

#endif // SHOWRESULT_H
