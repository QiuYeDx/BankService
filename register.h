#ifndef REGISTER_H
#define REGISTER_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
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
    QLineEdit *user, *pass;
    QLabel *label_user, *label_pass;
};

#endif // REGISTER_H
