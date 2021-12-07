#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <QPushButton>
#include <takenumber.h>
#include <windows.h>
#include <showresult.h>
#include <storage.h>
namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT
public slots:
    void showQuHao();
    void showChuangKou();
    void showZhanShi();
    void showCunChu();
public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private:
    Ui::MainMenu *ui;
    QPushButton *btn_1, *btn_2, *btn_3, *btn_4;
    TakeNumber *ui_takeNumber;
    Windows *ui_windows;
    ShowResult *ui_showResult;
    Storage *ui_storage;
};

#endif // MAINMENU_H
