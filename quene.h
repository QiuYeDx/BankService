#ifndef QUENE_H
#define QUENE_H

#include "user.h"
#include"QDebug"
/*取号等待队列*/
class QNode
{
private:
    User* data;
    QNode* next;
public:
    QNode(int ID,int type);
    QNode(QNode& origin);
    QNode* getNext();
    bool changeNext(QNode* in);
    User* getUser();

};

class Quene
{
private:
    QNode* front;
    QNode* rear;
    int count;
public:
    Quene();
    bool isEmpty() const;
    bool enQuene(int ID,int type);//讲用户指针传入,因此每个用户都需要new一下
    User* deQuene();
    void output();
    User* getFront();//寻找到ID最小的用户，并返回他的指针，未找到则返回空指针
    User* getFirstWaiting();
    User* findLastOne();
};

#endif // QUENE_H
