#include "counter.h"

Counter::Counter():occupied(false), user(nullptr)
{

}


int calloc(int type)
{
    if(type == 0)  //普通
    {
        if(quene_a.isEmpty())
            return -1;
        else
        {
            if(quene_b.isEmpty())
            {
                for(int i = 0; i<NORMCNT+SPECCNT;i++)
                {
                    if(counters[i].occupied==false)
                    {
                        counters[i].occupied = true;
                        return i;
                    }
                }
                return -1;
                //可以用特殊
            }
            else
            {
                for(int i = 0;i<NORMCNT;i++)
                {
                    if(counters[i].occupied == false)
                    {
                        counters[i].occupied = true;
                        return i;
                    }
                }
                return -1;
                //不可以用特殊
            }
        }

    }
    else  //特殊窗口
    {
        if(quene_b.isEmpty())
            return -1;
        else
        {
            for(int i = NORMCNT;i<SPECCNT+NORMCNT;i++)
            {
                if(counters[i].occupied == false)
                {
                    counters[i].occupied = true;
                    return i;
                }
            }
        }

    }
}
