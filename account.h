#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <QString>
#include "transaction.h"
#include <vector>
#define WRONG -1
#define SUCCESS 0

class Account
{
public:
    Account();
    QString password;
    int Balance;
    std::vector<Transaction> container;
    int changePassword(QString password, QString newpassword); //改密码，密码错误返回-1，成功返回0，有宏
    int makeTrans(QDateTime time, float amount, int type); //IN 1 OUT -1

};

#endif // ACCOUNT_H
