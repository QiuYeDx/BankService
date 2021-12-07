#ifndef REGISTER_H
#define REGISTER_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QFile>
#include <QTextStream>

extern QString filepath ;

namespace Ui {
class Register;
}

class Register : public QMainWindow
{
    Q_OBJECT
public slots:
    void showUp();
    void regist();
public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private:
    Ui::Register *ui;
    QPushButton *btn_reg;
    QLineEdit *user, *pass, *num, *num_2;
    QLabel *label_user, *label_pass, *label_num, *label_num_2;
};

#endif // REGISTER_H
