#pragma once

#include "Customer.h"
#include "Item.h"

/**
 * Creates a new transaction object with the given customer, item, and transaction type.
 *
 * @param customer A pointer to the customer associated with the transaction.
 * @param item A pointer to the item involved in the transaction.
 * @param type A string representing the type of the transaction (e.g., "borrow" or "return").
 * @pre The customer and item pointers must be valid and not null.
 * @post A new Transaction object is created with the given customer, item, and type.
 */
class Transaction
{
   
public:
   Transaction(Customer* customer, Item* item, string type);

   Customer* customer;
   Item* item;
   string type;
};