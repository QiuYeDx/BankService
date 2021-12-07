#include "accountbook.h"

AccountBook::AccountBook()
{

}

void AccountBook::save()
{
    //todo
}

Account* AccountBook::query(QString id, QString password)
{
    if(this->entry[id].password != password)
    {
        return nullptr;
    }
    else
    {
        return &(this->entry[id]);
    }
}


