#include "accountbook.h"

AccountBook::AccountBook()
{
    //todo
}

int AccountBook::save()
{
    QFile data("accountbook.txt");
    if(!data.open(QIODevice::WriteOnly | QIODevice::Text))
        return WRONG;
    QTextStream out(&data);
    for(auto it = this->entry.begin();it!=this->entry.end();it++)
    {
        out << it->first << Qt::endl;
        out << it->second.password << Qt::endl;
        out << it->second.Balance << Qt::endl;
        out << it->second.container.size() << Qt::endl;
        for(auto ita = it->second.container.begin(); ita!= it->second.container.end();ita++)
        {
            out << (ita->time).toString() << Qt::endl;
            out << ita->amount << Qt::endl;
            out << ita->type <<Qt::endl;
        }
    }

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


