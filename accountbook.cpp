#include "accountbook.h"
using namespace Qt;

extern QString filepath;
AccountBook::AccountBook()
{
    //todo
}

int AccountBook::save()
{
    QFile data(filepath+"/accountbook.txt");
    if(!data.open(QIODevice::WriteOnly | QIODevice::Text))
        return WRONG;
    QTextStream out(&data);
    out << this->entry.size() << endl;
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
    return SUCCESS;

}

int AccountBook::load()
{
    QFile data(filepath+"/accountbook.txt");
    if(!data.open(QIODevice::ReadOnly | QIODevice::Text))
        return WRONG;
    QTextStream in(&data);
    int n = in.readLine().toInt();
    for(int i = 0;i<n;i++)
    {
        QString ID = in.readLine();
        QString password = in.readLine();
        float balance = in.readLine().toFloat();
        int k = in.readLine().toInt();
        std::vector<Transaction> t;
        t.resize(k);

        QDateTime time;
        float amount;
        int type;
        for(int j = 0;j<k;j++)
        {
            time = QDateTime::fromString(in.readLine());
            amount = in.readLine().toFloat();
            type = in.readLine().toInt();
            t.emplace_back(time, amount, type);
        }
        Account tmp;
        tmp.Balance = balance;
        tmp.password = password;
        tmp.container = t;
        this->entry.emplace(ID, tmp);
    }


    return SUCCESS;

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

void AccountBook::addAccount(QString pass, QString id)
{
    Account tmp;
    tmp.Balance = 0;
    tmp.password = pass;
    entry.emplace(id,tmp);
}

