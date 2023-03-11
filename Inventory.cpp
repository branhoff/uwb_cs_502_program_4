//--------------------------------------------------------------------
// INVENTORY.CPP
// Implementation of the Inventory class
// Author: Brandon Hoffman
//--------------------------------------------------------------------
// Inventory class:
//   Implements an inventory management system that tracks items and transactions
//   using the following methods:
//      Inventory - constructor that initializes an empty inventory
//      ~Inventory - destructor that deallocates memory used by the inventory
//      addItem - adds an item to the inventory
//      removeItem - removes an item from the inventory
//      getItem - retrieves an item from the inventory by ID
//      addTransaction - adds a transaction to the inventory
//      displayAll - displays the inventory of items
//      displayForCustomer - displays the transaction history for a given customer
//   Assumptions:
//      - The addItem method assumes that the item ID is unique
//      - The removeItem method assumes that the item exists in the inventory
//      - The getItem method assumes that the item exists in the inventory
//      - The addTransaction method assumes that the customer and item exist in the inventory
//      - The displayForCustomer method assumes that the customer exists in the inventory
//--------------------------------------------------------------------

#include <fstream>
#include <algorithm>

#include "Inventory.h"
#include "Coin.h"
#include "Comic.h"
#include "Sport.h"

/**
 * Compares two Transaction objects based on the year of their items.
 *
 * @param t1 The first Transaction to compare.
 * @param t2 The second Transaction to compare.
 * @return Returns true if the year of the item in t1 is less than the year of the item in t2, false otherwise.
 *
 * @pre t1 and t2 must be valid Transaction objects with non-nullptr item pointers.
 * @post None.
 */
bool compareTransaction(Transaction* t1, Transaction* t2)
{
   return t1->item->getYear() < t2->item->getYear();
}

/**
 * Compares two Item objects based on their values and returns a boolean indicating their order.
 *
 * @param i1 A pointer to the first Item object to compare.
 * @param i2 A pointer to the second Item object to compare.
 * @return Returns true if i1 is less than i2, false otherwise.
 *
 * @pre The Item objects being compared must be valid and contain appropriate values.
 * @post The Item objects are not modified by this function.
 */
bool compareItem(Item* i1, Item* i2)
{
   return i1->compare(i2) < 0;
}

/**
 * Compares two customers based on their first and last names.
 *
 * @param c1 The first customer to compare.
 * @param c2 The second customer to compare.
 * @return Returns true if c1 should come before c2 in a sorted list, false otherwise.
 *
 * @pre Both c1 and c2 must be initialized with valid data.
 * @post The order of c1 and c2 is determined based on their first and last names.
 */
bool compareCustomer(Customer* c1, Customer* c2)
{
   return c1->getFullName() < c2->getFullName();
}

/**
 * @brief Constructs an empty Inventory object.
 *
 * @pre None.
 * @post An empty Inventory object is created.
 */
Inventory::Inventory()
{

}

/**
 * @brief Destructor for the Inventory class.
 *
 * Pre-condition: An Inventory object has been instantiated.
 *
 * Post-condition: All dynamically allocated memory for Coin, Comic, Sport, Customer, and Transaction objects
 * has been freed, and the Inventory object has been destroyed.
 *
 */
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
      Customer* customer = it->second;
      delete customer;
   }

   for (auto it = transactions.begin(); it != transactions.end(); ++it)
   {
      delete (*it);
   }
}

/**
 * Read inventory from a given file path.
 *
 * @param path The path to the input file.
 * @return Returns 0 on success, -1 on error.
 *
 * @pre The input file at the given path exists.
 * @post The items in the input file have been added to the inventory.
 */
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

      Item* item = nullptr;

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

/**
 * Reads customer information from a given file and adds them to the inventory.
 *
 * @param path The path of the file to read from.
 * @return 0 if the file was successfully read and customer information was added to the inventory, -1 if the file could not be opened.
 *
 * Pre-conditions:
 * - `path` is a valid file path to an existing file that can be read from.
 *
 * Post-conditions:
 * - If the file at `path` was successfully read, `customers` vector contains new Customer objects with information from the file.
 * - If the file could not be opened, an error message is printed to the console and the function returns -1.
 */
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
      customers.insert({ id, customer });
   }

   return 0;
}
/**
 * Parses commands from a file and executes them on the Inventory object.
 *
 * @param path The path to the file containing the commands.
 * @return Returns 0 on success, -1 if the file does not exist or could not be opened.
 *
 * @pre The Inventory object must be initialized with valid data and items.
 * @pre The file at the specified path must exist and be readable.
 * @post The Inventory object is modified according to the commands in the file.
 * @post Transactions are added to the Inventory's transaction history.
 * @post Items are added or removed from the Inventory's items.
 * @post Customers may be added to the Inventory's customers if they are referenced in the file.
 */
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
         if (customer == nullptr)
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

            Item* item = nullptr;

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

            if (item != nullptr)
            {
               Item* exist = findItem(item);

               if (exist == nullptr)
               {
                  if (transactionType == 'S') // sell
                  {
                     cout << "there is no inventory for item " << item->getInfo() << endl;
                     delete item;
                  }
                  item->setCount(1);
                  vector<Item*>* items = findItems(item->getType());
                  if (items != nullptr)
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
                     if (exist->getCount() < 1)
                     {
                        cout << "there is no inventory for item " << item->getInfo() << endl;
                     }
                     else
                     {
                        exist->decreaseCount();
                        Transaction* trans = new Transaction(customer, exist, "Sell");
                        transactions.push_back(trans);
                     }
                  }
                  else // Buy
                  {
                     exist->increaseCount();

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

/**
 * Find a customer in the inventory by their ID.
 *
 * @param id The ID of the customer to find.
 * @return A pointer to the customer object if found, nullptr otherwise.
 *
 * Pre-conditions:
 * - The inventory must contain at least one customer object.
 * - The ID parameter must not be empty or nullptr.
 *
 * Post-conditions:
 * - If a customer object with the given ID is found in the inventory, a pointer to that object is returned.
 * - If a customer object with the given ID is not found in the inventory, nullptr is returned.
 * - The state of the inventory is not modified by this method.
 */
Customer* Inventory::findCustomer(string id)
{
   auto it = customers.find(id);
   if (it == customers.end())
      return nullptr;

   return it->second;
}

/**
 * Returns a pointer to a vector containing all items of the specified type.
 *
 * @param type The type of items to search for. 'M' for coins, 'C' for comics, or 'S' for sports.
 * @return Returns a pointer to a vector containing all items of the specified type, or nullptr if the type is invalid.
 *
 * @pre The Inventory object must be initialized with valid data and items.
 * @post Returns a pointer to a vector containing all items of the specified type, or nullptr if the type is invalid.
 */
vector<Item*>* Inventory::findItems(char type)
{
   vector<Item*>* items = nullptr;

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

/**
 * Finds an item in the Inventory based on its type and attributes.
 *
 * @param item A pointer to the item to find.
 * @return Returns a pointer to the item if found, or nullptr if not found.
 *
 * @pre The Inventory object must be initialized with valid data and items.
 * @post None.
 *
 * This method first calls the findItems method to get a vector of items of the same type as the item to be found.
 * It then iterates through the vector to find an item that matches the given item's attributes using the compare method.
 * If found, a pointer to the matching item is returned. If not found, nullptr is returned.
 */
Item* Inventory::findItem(Item* item)
{
   if (item == nullptr)
      return nullptr;

   vector<Item*>* items = findItems(item->getType());
   if (items == nullptr)
      return nullptr;

   for (auto it = items->begin(); it != items->end(); ++it)
   {
      Item* row = *it;
      if (row->compare(item) == 0)
         return row;
   }

   return nullptr;
}


/**
 * Displays the transaction history for a specific customer in the inventory,
 * sorted chronologically by transaction date.
 *
 * @param id The ID of the customer whose transaction history is to be displayed.
 *
 * @pre The Inventory object must be initialized with valid data and items.
 * @post The transaction history for the specified customer is printed to the console,
 *       sorted chronologically by transaction date.
 *       If there are no transactions for the specified customer, a message is printed
 *       indicating that there are no transactions.
 */
void Inventory::displayForCustomer(string id)
{
   cout << endl << "-------- Transaction of Customer " << id << " ---------- - " << endl;
   vector<Transaction*> transForCustomer;
   for (auto it = transactions.begin(); it != transactions.end(); ++it)
   {
      Transaction* trans = *it;
      if (trans->customer->getId() != id)
         continue;
      transForCustomer.push_back(trans);
   }

   // sort transactions in chronological order
   std::sort(transForCustomer.begin(), transForCustomer.end(), compareTransaction);

   // display transactions
   for (auto it = transForCustomer.begin(); it != transForCustomer.end(); ++it)
   {
      Transaction* trans = *it;
      cout << "Customer " << trans->customer->getFullName() << " " << trans->type << ": " << trans->item->getInfo() << endl;
   }

   if (transForCustomer.size() < 1)
   {
      cout << "There is no transaction for customer " << id << endl;
   }

   cout << endl;

}


/**
 * Displays the current inventory of items in the console.
 *
 * @pre The Inventory object must be initialized with valid data and items.
 * @post The current inventory of items is displayed in the console.
 */
void Inventory::displayInventory()
{
   cout << endl << "-------- Inventory -----------" << endl;

   cout << endl << "----- Coin List -----" << endl;
   std::sort(coins.begin(), coins.end(), compareItem);
   for (auto it = coins.begin(); it != coins.end(); ++it)
   {
      Item* item = *it;

      int count = item->getCount();
      if (count < 1)
         continue;

      cout << item->getInfo() << ", Count = " << count << endl;
   }

   cout << endl << "----- Comics List -----" << endl;
   std::sort(comics.begin(), comics.end(), compareItem);
   for (auto it = comics.begin(); it != comics.end(); ++it)
   {
      Item* item = *it;

      int count = item->getCount();

      if (count < 1)
         continue;

      cout << item->getInfo() << ", Count = " << count << endl;
   }

   cout << endl << "----- Sports List -----" << endl;
   std::sort(sports.begin(), sports.end(), compareItem);
   for (auto it = sports.begin(); it != sports.end(); ++it)
   {
      Item* item = *it;

      int count = item->getCount();
      if (count < 1)
         continue;

      cout << item->getInfo() << ", Count = " << count << endl;
   }
   cout << endl;
}

/**
 * Displays the transaction history of all customers in the inventory,
 * sorted alphabetically by customer name and then chronologically by transaction date.
 *
 * @pre The Inventory object must be initialized with valid data and items.
 * @post The transaction history of all customers in the inventory is printed to the console.
 *       Transactions are sorted by customer name and then by transaction date.
 */
void Inventory::displayHistory()
{
   cout << endl << "-------- History -----------" << endl;

   // sort customer first
   vector<Customer*> sorted;
   for (auto it = customers.begin(); it != customers.end(); ++it)
   {
      Customer* customer = it->second;
      sorted.push_back(customer);
   }

   std::sort(sorted.begin(), sorted.end(), compareCustomer);

   for (auto it = sorted.begin(); it != sorted.end(); ++it)
   {
      Customer* customer = *it;
      displayForCustomer(customer->getId());
   }
}

