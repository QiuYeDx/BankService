#ifndef ACCOUNTBOOK_H
#define ACCOUNTBOOK_H
#include "account.h"
#include <QString>
#include <map>


class AccountBook
{
public:
    AccountBook();
    std::map<QString,Account> entry;
    void save(); //保存到文件
    Account* query(QString id, QString password); //返回对应账户的account对象，密码错误将会返回空指针

};

#endif // ACCOUNTBOOK_H
