#ifndef QUENE_H
#define QUENE_H

#include "user.h"
#include"QDebug"
/*取号等待队列*/

class Quene
{
private:
    int count;
    int front,rear;
    User** data;//存储每一个等待客户的指针
    int length;
public:
    Quene(int len);
    bool isEmpty() const;
    bool push(int ID,int type);//讲用户指针传入,因此每个用户都需要new一下
    User* pop();
    void output();
};

#endif // QUENE_H
