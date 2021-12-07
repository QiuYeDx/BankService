#ifndef COUNTER_H
#define COUNTER_H
#include "user.h"
#include "quene.h"
#define NORMCNT 8
#define SPECCNT 4
class Counter
{
public:
    bool occupied; //当前窗口是否被占用
    User* user;  //指向正在被服务的客户
    Counter();
};


//todo 实现分配，传特殊还是普通业务
extern Counter counters[];
extern Quene quene_a;
extern Quene quene_b;
int calloc(int type); //0是一般 1是特殊 指的是用户的种类 返回值是分配的窗口的数组下标，从0开始
#endif // COUNTER_H
