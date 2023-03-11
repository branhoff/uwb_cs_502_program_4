//--------------------------------------------------------------------
// TRANSACTION.CPP
// Implementation of the Transaction class
// Author: Brandon Hoffman
//--------------------------------------------------------------------
// Transaction class:
//   Implements a transaction object that represents a single transaction between a customer and an item
//   using the following methods:
//      Transaction - constructor that initializes a new transaction object
//   Assumptions:
//      - The pointers to customer and item passed to the constructor are valid and not nullptr
//--------------------------------------------------------------------

#include "Transaction.h"

/**
 * Creates a new transaction object with the given customer, item, and transaction type.
 *
 * @param customer A pointer to the customer associated with the transaction.
 * @param item A pointer to the item involved in the transaction.
 * @param type A string representing the type of the transaction (e.g., "borrow" or "return").
 * @pre The customer and item pointers must be valid and not nullptr.
 * @post A new Transaction object is created with the given customer, item, and type.
 */
Transaction::Transaction(Customer* customer, Item* item, string type)
{
   this->customer = customer;
   this->item = item;
   this->type = type;
}