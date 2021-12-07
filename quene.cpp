#include "quene.h"

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

bool Quene::push(User *apd)
{
    if(count<length)
    {
        data[rear]=apd;
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


