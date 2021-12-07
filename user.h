#ifndef USER_H
#define USER_H

#include<QDateTime>

class User
{
public:
    int ID;
    int type;//业务类型:一般/特殊
    int status;//状态:等待/业务中
    QDateTime tm_quene;
    QDateTime tm_start;
    QDateTime tm_end;
public:
    User(int id,int type);
    //User();
    User(User& origin);
};

#endif // USER_H
