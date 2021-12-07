#include "user.h"

User::User(int id,int type)
{
    ID=id;
    this->type=type;
    status=0;
    tm_quene=QDateTime::currentDateTime();
}


User::User(User& origin):
    ID(origin.ID),
    type(origin.type),
    status(origin.status),
    tm_quene(origin.tm_quene),
    tm_start(origin.tm_start),
    tm_end(origin.tm_end)
{}
