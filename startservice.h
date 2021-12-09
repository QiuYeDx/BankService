#ifndef STARTSERVICE_H
#define STARTSERVICE_H

#include <QMainWindow>
#include <QLabel>
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

private:
    Ui::StartService *ui;
    int ID;
    QLabel *label_1, *label_2;
};

#endif // STARTSERVICE_H
