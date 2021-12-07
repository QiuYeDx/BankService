#include "quenemanager.h"

#include"quene.h"

QueneManager::QueneManager()
{
    quene_type_a = new Quene(30);
    quene_type_b = new Quene(30);
    num=0;
}

void QueneManager::append_to_a()
{
    quene_type_a->push(++num);
}

void QueneManager::append_to_b()
{
    quene_type_b->push(++num);
}



