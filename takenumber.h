#ifndef TAKENUMBER_H
#define TAKENUMBER_H

#include <QMainWindow>

namespace Ui {
class TakeNumber;
}

class TakeNumber : public QMainWindow
{
    Q_OBJECT

public:
    explicit TakeNumber(QWidget *parent = nullptr);
    ~TakeNumber();

private:
    Ui::TakeNumber *ui;
};

#endif // TAKENUMBER_H
