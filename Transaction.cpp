#include "Transaction.h"

Transaction::Transaction(Customer* customer, Item* item, string type)
{
   this->customer = customer;
   this->item = item;
   this->type = type;
}