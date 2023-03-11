#pragma once

#include <vector>
#include "Item.h"
#include "Customer.h"
#include "Transaction.h"

class Inventory
{
private:
   vector<Item*> coins;
   vector<Item*> comics;
   vector<Item*> sports;
   vector<Customer*> customers;
   vector<Transaction*> transactions;
   
public:
   Inventory();
   ~Inventory();
   int readInventory(string path);
   int readCustomer(string path);
   int parseCommands(string path);

   Customer* findCustomer(string id);
   Item* findItem(Item* item);
   vector<Item*>* findItems(char type);
   void displayForCustomer(string id);
   void displayInventory();
   void displayHistory();
};

