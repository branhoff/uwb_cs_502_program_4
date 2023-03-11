#include <fstream>
#include <algorithm>

#include "Inventory.h"
#include "Coin.h"
#include "Comic.h"
#include "Sport.h"

Inventory::Inventory()
{

}

Inventory::~Inventory()
{
   for (auto it = coins.begin(); it != coins.end(); ++it)
   {
      delete (*it);
   }

   for (auto it = comics.begin(); it != comics.end(); ++it)
   {
      delete (*it);
   }


   for (auto it = sports.begin(); it != sports.end(); ++it)
   {
      delete (*it);
   }

   for (auto it = customers.begin(); it != customers.end(); ++it)
   {
      delete (*it);
   }

   for (auto it = transactions.begin(); it != transactions.end(); ++it)
   {
      delete (*it);
   }
}

int Inventory::readInventory(string path)
{
   ifstream input(path);

   if (!input.is_open())
   {
      cout << path << " does not exist" << endl;
      return -1;
   }

   string type, stringCount, stringYear, grade, description;
   string coinType, title, publisher, player, manufacturer;
   int count = 0, year = 0;
   
   while (!input.eof())
   {
      std::getline(input, type, ','); 		//get type of inventory
      input.get(); 			//discard space 
      std::getline(input, stringCount, ','); 	//get count
      count = atoi(stringCount.c_str());
      input.get(); 			//discard space

      Item* item = NULL;

      if (type == "M") // coin
      {
         std::getline(input, stringYear, ','); 		//get year of inventory
         year = atoi(stringYear.c_str());
         input.get(); 			//discard space 

         std::getline(input, grade, ','); 		//get grade of inventory
         input.get(); 			//discard space

         std::getline(input, coinType, '\n'); 		//get rest of inventory      
         item = new Coin(year, grade, coinType);
         item->setCount(count);

         coins.push_back(item);
      }
      else if (type == "C") // Comic
      {
         std::getline(input, stringYear, ','); 		//get year of inventory
         year = atoi(stringYear.c_str());
         input.get(); 			//discard space 

         std::getline(input, grade, ','); 		//get grade of inventory
         input.get(); 			//discard space

         std::getline(input, title, ','); 		//get title of inventory
         input.get(); 			//discard space

         std::getline(input, publisher, '\n'); 		//get rest of inventory  
         item = new Comic(year, grade, title, publisher);
         item->setCount(count);

         comics.push_back(item);
      }
      else if (type == "S") // Sport Card
      {
         std::getline(input, stringYear, ','); 		//get year of inventory
         year = atoi(stringYear.c_str());
         input.get(); 			//discard space 

         std::getline(input, grade, ','); 		//get grade of inventory
         input.get(); 			//discard space

         std::getline(input, player, ','); 		//get player of inventory
         input.get(); 			//discard space

         std::getline(input, manufacturer, '\n'); 		//get rest of inventory   
         item = new Sport(year, grade, player, manufacturer);
         item->setCount(count);

         sports.push_back(item);
      }
      else
      {
         getline(input, description, '\n'); 	//get rest of info
      }

   }

   return 0;
}

int Inventory::readCustomer(string path)
{
   ifstream input(path);

   if (!input.is_open())
   {
      cout << path << " does not exist" << endl;
      return -1;
   }

   string id, firstName, lastName;
   
   while (!input.eof())
   {
      std::getline(input, id, ','); 		//get id
      input.get(); 			//discard space 
      input >> firstName; 	// get firstName    
      input.get(); 			//discard space 
      std::getline(input, lastName, '\n'); 		//get rest    

      Customer* customer = new Customer(id, firstName, lastName);
      customers.push_back(customer);
   }

   return 0;
}

int Inventory::parseCommands(string path)
{
   ifstream input(path);

   if (!input.is_open())
   {
      cout << path << " does not exist" << endl;
      return -1;
   }

   char transactionType;
   string customerID;

   string type, stringCount, stringYear, grade, description;
   string coinType, title, publisher, player, manufacturer;
   int count = 0, year = 0;

   while (!input.eof())
   {
      // get transaction type
      input >> transactionType;
      if (transactionType == 'S' || transactionType == 'B' || transactionType == 'C') // sell/buy/customer
      {
         input.get(); 			//discard space 
         input.get(); 			//discard space 
         // read customer id

         if (transactionType == 'C') // customer
         {
            input >> customerID;
         }
         else
         {
            std::getline(input, customerID, ',');
         }
         
         // check if customer id exist
         Customer* customer = findCustomer(customerID);
         if (customer == NULL)
         {
            std::getline(input, description, '\n'); 		//get rest
            cout << "Customer: " << customerID << " not exist" << endl;
            continue;
         }

         if (transactionType == 'C') // customer
         {
            displayForCustomer(customerID);
         }

         if (transactionType == 'S' || transactionType == 'B') // sell/buy
         {
            input.get(); 			//discard space 

            std::getline(input, type, ','); 		//get type of inventory
            input.get(); 			//discard space 
            
            Item* item = NULL;

            if (type == "M") // coin
            {
               std::getline(input, stringYear, ','); 		//get year of inventory
               year = atoi(stringYear.c_str());
               input.get(); 			//discard space 

               std::getline(input, grade, ','); 		//get grade of inventory
               input.get(); 			//discard space

               std::getline(input, coinType, '\n'); 		//get rest of inventory      
               item = new Coin(year, grade, coinType);
            }
            else if (type == "C") // Comic
            {
               std::getline(input, stringYear, ','); 		//get year of inventory
               year = atoi(stringYear.c_str());
               input.get(); 			//discard space 

               std::getline(input, grade, ','); 		//get grade of inventory
               input.get(); 			//discard space

               std::getline(input, title, ','); 		//get title of inventory
               input.get(); 			//discard space

               std::getline(input, publisher, '\n'); 		//get rest of inventory  
               item = new Comic(year, grade, title, publisher);
            }
            else if (type == "S") // Sport Card
            {
               std::getline(input, stringYear, ','); 		//get year of inventory
               year = atoi(stringYear.c_str());
               input.get(); 			//discard space 

               std::getline(input, grade, ','); 		//get grade of inventory
               input.get(); 			//discard space

               std::getline(input, player, ','); 		//get player of inventory
               input.get(); 			//discard space

               std::getline(input, manufacturer, '\n'); 		//get rest of inventory   
               item = new Sport(year, grade, player, manufacturer);
            }
            else
            {
               getline(input, description, '\n'); 	//get rest of info
            }

            if (item != NULL)
            {
               Item* exist = findItem(item);
               
               if (exist == NULL)
               {
                  if (transactionType == 'S') // sell
                  {
                     cout << "there is no inventory for item " << item->getInfo() << endl;
                     delete item;
                  }
                  item->setCount(1);
                  vector<Item*>* items = findItems(item->type);
                  if (items != NULL)
                  {
                     items->push_back(item);
                     Transaction* trans = new Transaction(customer, item, "Buy");
                     transactions.push_back(trans);
                  }
               }
               else
               {
                  if (transactionType == 'S')
                  {
                     if (exist->count < 1)
                     {
                        cout << "there is no inventory for item " << item->getInfo() << endl;
                     }
                     else
                     {
                        exist->count--;
                        Transaction* trans = new Transaction(customer, exist, "Sell");
                        transactions.push_back(trans);
                     }
                  }
                  else // Buy
                  {
                     exist->count++;

                     Transaction* trans = new Transaction(customer, exist, "Buy");
                     transactions.push_back(trans);
                  }
                  delete item;
               }
            }
            else
            {
               cout << "Invalid Item Type: " << type << endl;
            }
         }
      }
      else if (transactionType == 'D')
      {
         displayInventory();
      }
      else if (transactionType == 'H')
      {
         displayHistory();
      }
      else
      {
         std::getline(input, description, '\n'); 		//get rest
      }

      transactionType = ' ';

   }
   return 0;
}

Customer* Inventory::findCustomer(string id)
{
   for (auto it = customers.begin(); it != customers.end(); ++it)
   {
      Customer* customer = *it;
      if (customer->id == id)
         return customer;
   }

   return NULL;
}

vector<Item*>* Inventory::findItems(char type)
{
   vector<Item*>* items = NULL;

   if (type == 'M') // coin
   {
      items = &coins;
   }

   if (type == 'C') // comics
   {
      items = &coins;
   }

   if (type == 'S') // sports
   {
      items = &sports;
   }

   return items;
}

Item* Inventory::findItem(Item* item)
{
   if (item == NULL)
      return NULL;

   vector<Item*>* items = findItems(item->type);
   if (items == NULL)
      return NULL;

   for (auto it = items->begin(); it != items->end(); ++it)
   {
      Item* row = *it;
      if (row->compare(item) == 0)
         return row;
   }

   return NULL;
}

bool compareTransaction(Transaction* t1, Transaction* t2)
{
   return t1->item->year < t2->item->year;
}

void Inventory::displayForCustomer(string id)
{
   cout << endl << "-------- Transaction of Customer " << id << " ---------- - " << endl;
   vector<Transaction*> transForCustomer;
   for (auto it = transactions.begin(); it != transactions.end(); ++it)
   {
      Transaction* trans = *it;
      if (trans->customer->id != id)
         continue;
      transForCustomer.push_back(trans);
   }

   // sort transactions in chronological order
   std::sort(transForCustomer.begin(), transForCustomer.end(), compareTransaction);

   // display transactions
   for (auto it = transForCustomer.begin(); it != transForCustomer.end(); ++it)
   {
      Transaction* trans = *it;
      cout << "Customer " << trans->customer->firstName << " " << trans->customer->lastName << " " << trans->type << ": " << trans->item->getInfo() << endl;
   }

   if (transForCustomer.size() < 1)
   {
      cout << "There is no transaction for customer " << id << endl;
   }

   cout << endl;

}

bool compareItem(Item* i1, Item* i2)
{
   return i1->compare(i2) < 0;
}

void Inventory::displayInventory()
{
   cout << endl << "-------- Inventory -----------" << endl;

   cout << endl << "----- Coin List -----" << endl;
   std::sort(coins.begin(), coins.end(), compareItem);
   for (auto it = coins.begin(); it != coins.end(); ++it)
   {
      Item* item = *it;

      if (item->count < 1)
         continue;

        cout << item->getInfo() << ", Count = " << item->count << endl;
   }

   cout << endl << "----- Comics List -----" << endl;
   std::sort(comics.begin(), comics.end(), compareItem);
   for (auto it = comics.begin(); it != comics.end(); ++it)
   {
      Item* item = *it;

      if (item->count < 1)
         continue;

      cout << item->getInfo() << ", Count = " << item->count << endl;
   }

   cout << endl << "----- Sports List -----" << endl;
   std::sort(sports.begin(), sports.end(), compareItem);
   for (auto it = sports.begin(); it != sports.end(); ++it)
   {
      Item* item = *it;

      if (item->count < 1)
         continue;

      cout << item->getInfo() << ", Count = " << item->count << endl;
   }
   cout << endl;
}

bool compareCustomer(Customer* c1, Customer* c2)
{
   if (c1->firstName < c2->firstName)
      return true;
   if (c1->firstName > c2->firstName)
      return false;

   return c1->lastName < c2->lastName;
}
void Inventory::displayHistory()
{
   cout << endl << "-------- History -----------" << endl;

   // sort customer first
   std::sort(customers.begin(), customers.end(), compareCustomer);

   for (auto it = customers.begin(); it != customers.end(); ++it)
   {
      Customer* customer = *it;
      displayForCustomer(customer->id);
   }
}