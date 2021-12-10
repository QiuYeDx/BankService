#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <QDateTime>
#define IN 1
#define OUT -1

class Transaction
{
public:
    QDateTime time;
    float amount;
    int type;
    Transaction();
    Transaction(QDateTime, float, int);

};

#endif // TRANSACTION_H
