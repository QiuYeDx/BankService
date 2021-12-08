#ifndef SHOWRESULT_H
#define SHOWRESULT_H

#include <QMainWindow>
#include <QLabel>
#include <QFile>
#include <QDate>

extern QString filepath;

namespace Ui {
class ShowResult;
}

class ShowResult : public QMainWindow
{
    Q_OBJECT

public:
    explicit ShowResult(QWidget *parent = nullptr);
    ~ShowResult();
    void getResult();

private:
    Ui::ShowResult *ui;
    QLabel *label_1, *label_2, *Label_3, *label_4,*label;
};

#endif // SHOWRESULT_H
