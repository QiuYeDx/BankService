#ifndef ACCOUNTBOOK_H
#define ACCOUNTBOOK_H
#include "account.h"

class AccountBook
{
public:
    AccountBook();
    std::vector<Account> entry;
    void save();
    void find();
};

#endif // ACCOUNTBOOK_H
