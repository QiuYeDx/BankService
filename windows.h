#ifndef WINDOWS_H
#define WINDOWS_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QFile>
#include "takenumber.h"
#include "startservice.h"

extern QString filepath ;

namespace Ui {
class Windows;
}

class Windows : public QMainWindow
{
    Q_OBJECT
public slots:
    void Service();
    void updateInformation(int index);
public:
    explicit Windows(QWidget *parent = nullptr);
    ~Windows();
    void showService();
private:
    Ui::Windows *ui;
    QPushButton *btn_switch;
    QLabel *label_1, *label_2, *label_3, *label_4;
    QComboBox *comboBox;
    StartService *ui_service;
};

#endif // WINDOWS_H
