#include "transaction.h"

Transaction::Transaction()
{
}

Transaction::Transaction(QDateTime time, float amount, int type)
{
    this->time = time;
    this->amount = amount;
    this->type = type;
}
