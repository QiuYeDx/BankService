#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mainmenu.h>
#include <register.h>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

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
    void logIn();
private:
    Ui::MainWindow *ui;
    MainMenu *ui_mainMenu;
    Register *ui_register;
    QPushButton *btn_login, *btn_reg;
    QLineEdit *user, *pass;
    QLabel *label_user, *label_pass;
};
#endif // MAINWINDOW_H
