#include "quene.h"
//using namespace Qt;

Quene::Quene(int len)
{
    this->length=len;
    data=new User*[this->length];
    front=0;
    rear=0;
    count=0;
}

bool Quene::isEmpty() const
{
    if(count==0)
        return true;
    else return false;
}

bool Quene::push(int ID,int type)
{
    if(count<length)
    {
        data[rear]=new User(ID,type);
        rear++;
        count++;
        return true;
    }
    else return false;
}

User* Quene::pop()
{
    if(count==0)
        return nullptr;
    else
    {
        data[front]->tm_start=QDateTime::currentDateTime();
        User* temp=new User(*data[front]);
        for(int i=0;i<rear-1;i++)
        {
            data[i]=data[i+1];
        }
        rear--;
        count--;
        return temp;
    }
}

void Quene::output()
{
    qDebug()<<"quene"<<endl;
    for(int i=front;i<rear;i++)
        qDebug()<<data[i]->ID<<"   "<<data[i]->type<<"  "<<data[i]->status<<endl;

}

User* Quene::findMinimunID()
{
    int i=0;
    while(i<rear)
    {
        if(data[i]->counter==-1)
            return data[i];
    }
    return nullptr;
}


