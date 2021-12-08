#ifndef USER_H
#define USER_H

#include<QDateTime>

class User
{
public:
    int ID;
    int type;//业务类型:一般/特殊 一般0，特殊1
    int status;//状态:等待/业务中 等待是0，分配窗口1，业务中2
    int counter; // 被分配的窗口，-1是未分配
    QDateTime tm_quene;
    QDateTime tm_start;
    QDateTime tm_end;
public:
    User(int id,int type);
    //User();
    User(User& origin);
};

#endif // USER_H
