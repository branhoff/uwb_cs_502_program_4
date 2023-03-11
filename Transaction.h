#pragma once

#include "Customer.h"
#include "Item.h"

class Transaction
{
   
public:
   Transaction(Customer* customer, Item* item, string type);

   Customer* customer;
   Item* item;
   string type;
};