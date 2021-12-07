#ifndef WINDOWS_H
#define WINDOWS_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
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

private:
    Ui::Windows *ui;
    QPushButton *btn_switch;
    QLabel *label_1, *label_2, *label_3, *label_4;
    QComboBox *comboBox;
};

#endif // WINDOWS_H
