#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QString>
#include "transaction.h"
#include <vector>

class Account
{
public:
    Account();
    QString id;
    QString password;
    std::vector<Transaction> trans;
};

#endif // ACCOUNT_H
