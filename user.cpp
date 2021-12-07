#include "user.h"

User::User(int type)
{
    this->type=type;
    status=0;
    tm_quene=QDateTime::currentDateTime();
}
