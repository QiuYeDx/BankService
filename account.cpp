#include "account.h"

Account::Account()
{

}

int Account::changePassword(QString password, QString newpassword)
{
    if(this->password != password)
    {
        return WRONG;
    }
    else
    {
        this->password = newpassword;
        return SUCCESS;
    }

}

int Account::makeTrans(QDateTime time, float amount, int type)
{
    if(type == IN)
    {
        Transaction t;
        this->container.insert(container.end(),t);
        this->Balance += amount;
        return SUCCESS;
    }
    else
    {
        if(this->Balance-amount<0)
        {
            return WRONG;
        }
        Transaction t;
        this->container.insert(container.end(), t);
        this->Balance -= amount;
        return SUCCESS;

    }
}
