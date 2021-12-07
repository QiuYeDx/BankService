#include "transaction.h"

Transaction::Transaction()
{

}

Transaction::Transaction(QDateTime time, float amount, int type)
{
    this->amount = amount;
    this->time = time;
    this->type = type;
}
