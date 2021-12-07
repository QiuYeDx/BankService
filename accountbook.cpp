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
        out << it->first << endl;
        out << it->second.password << endl;
        out << it->second.Balance << endl;
        out << it->second.container.size() << endl;
        for(auto ita = it->second.container.begin(); ita!= it->second.container.end();ita++)
        {
            out << (ita->time).toString() << endl;
            out << ita->amount << endl;
            out << ita->type <<endl;
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


