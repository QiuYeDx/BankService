#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <QDateTime>
#define IN 1
#define OUT -1

class Transaction
{
public:
    Transaction();
    QDateTime time;
    int amount;
    int type;
};

#endif // TRANSACTION_H
