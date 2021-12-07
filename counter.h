#ifndef COUNTER_H
#define COUNTER_H
#include "user.h"

class Counter
{
public:
    bool occupied; //当前窗口是否被占用
    User* user;  //指向正在被服务的客户
    Counter();
};

#endif // COUNTER_H
