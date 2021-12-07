#ifndef ACCOUNTBOOK_H
#define ACCOUNTBOOK_H
#include "account.h"
#include <QString>
#include <map>
#include <QFile>
#include <QTextStream>

class AccountBook
{
public:
    AccountBook();
    std::map<QString,Account> entry;
    int save(); //保存到文件 SUCCESS 0 WRONG -1
    void load(); //从文件中读取
    Account* query(QString id, QString password); //返回对应账户的account对象，密码错误将会返回空指针

};

#endif // ACCOUNTBOOK_H
