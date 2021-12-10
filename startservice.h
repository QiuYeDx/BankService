#ifndef STARTSERVICE_H
#define STARTSERVICE_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QPushButton>

namespace Ui {
class StartService;
}

class StartService : public QMainWindow
{
    Q_OBJECT
public:
    StartService(int ID);
    explicit StartService(QWidget *parent = nullptr);
    ~StartService();

public slots:
    void login();
    void chooseServiceType(int index);

private:
    Ui::StartService *ui;
    int ID;
    QLabel *label_1, *label_2;
    QLabel *label_info ,*label_user,*label_pwd,*label_money;
    QLabel *label_3;
    QGroupBox* group_1 ,*group_2;
    QRadioButton *btn_1,*btn_2,*btn_3;
    QPushButton *btn_4;
    QVBoxLayout* layout_1,*layout_2;
    QLineEdit *line_user,*line_pwd,*line_money;
};

#endif // STARTSERVICE_H
