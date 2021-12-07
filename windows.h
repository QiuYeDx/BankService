#ifndef WINDOWS_H
#define WINDOWS_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
namespace Ui {
class Windows;
}

class Windows : public QMainWindow
{
    Q_OBJECT

public:
    explicit Windows(QWidget *parent = nullptr);
    ~Windows();

private:
    Ui::Windows *ui;
    QPushButton *btn_switch;
    QLabel *label_1, *label_2, *label_3, *label_4;
};

#endif // WINDOWS_H
