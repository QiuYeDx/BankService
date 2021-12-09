#include "quene.h"
using namespace Qt;

QNode::QNode(int ID,int type)
{
    data=new User(ID,type);
    next=nullptr;
}

QNode::QNode(QNode& origin):
    data(origin.data),
    next(origin.next)
{}

QNode* QNode::getNext()
{
    return this->next;
}

bool QNode::changeNext(QNode* in)
{
    this->next=in;
    return true;
}

User* QNode::getUser()
{
    return this->data;
}

Quene::Quene()
{
    front = nullptr;
    rear = nullptr;
    count=0;
}

bool Quene::isEmpty() const
{
    if(count==0)
        return true;
    else return false;
}

bool Quene::enQuene(int ID,int type)
{
    QNode*temp = new QNode(ID,type);
    if(front==nullptr)
    {
        front=temp;
        rear=temp;
    }else{
        rear->changeNext(temp);
        rear=temp;
    }
    count++;
    return true;
}

User* Quene::deQuene()
{
    if(count==0)
        return nullptr;
    else
    {
        count--;
        QNode* temp=front;
        if(front->getNext()==nullptr)
            rear=nullptr;
        front=front->getNext();
        temp->changeNext(nullptr);
        return temp->getUser();
    }
}

void Quene::output()
{
    qDebug()<<"quene:";
    QNode* temp=front;
    while(temp!=nullptr)
    {
        qDebug()<<temp->getUser()->ID<<"counter"<<temp->getUser()->counter<<endl;
        temp=temp->getNext();
    }
}

User* Quene::getFront()
{
    if(front==nullptr)
        return nullptr;
    return front->getUser();
}

User* Quene::getFirstWaiting()
{
    QNode* temp=front;
    while(temp!=nullptr&&temp->getUser()->counter!=-1)
        temp=temp->getNext();
    if(temp==nullptr)
        return nullptr;
    return temp->getUser();
}

User* Quene::findLastOne()
{
    if(rear==nullptr)
        return nullptr;
    return rear->getUser();
}


