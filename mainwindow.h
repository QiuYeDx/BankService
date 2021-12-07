#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mainmenu.h>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
//#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

private:
    Ui::MainWindow *ui;
    MainMenu *ui_mainMenu;
    QPushButton *btn_login, *btn_reg;
    QLineEdit *user, *pass;
    QLabel *label_user, *label_pass;
    //QTableWidget *table_widget;
};
#endif // MAINWINDOW_H
