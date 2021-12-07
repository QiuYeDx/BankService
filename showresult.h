#ifndef SHOWRESULT_H
#define SHOWRESULT_H

#include <QMainWindow>

namespace Ui {
class ShowResult;
}

class ShowResult : public QMainWindow
{
    Q_OBJECT

public:
    explicit ShowResult(QWidget *parent = nullptr);
    ~ShowResult();

private:
    Ui::ShowResult *ui;
};

#endif // SHOWRESULT_H
