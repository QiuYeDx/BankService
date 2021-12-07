#ifndef QUENESERVICE_H
#define QUENESERVICE_H

#include "quene.h"

class QueneManager
{
public:
    int num;
    Quene* quene_type_a;//一般业务队列
    Quene* quene_type_b;//特殊业务队列
public:
    QueneManager();
    void append_to_a();
    void append_to_b();


};

#endif // QUENESERVICE_H
