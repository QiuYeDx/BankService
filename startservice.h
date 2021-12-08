#ifndef STARTSERVICE_H
#define STARTSERVICE_H

#include <QMainWindow>

namespace Ui {
class StartService;
}

class StartService : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartService(QWidget *parent = nullptr);
    ~StartService();

private:
    Ui::StartService *ui;
};

#endif // STARTSERVICE_H
