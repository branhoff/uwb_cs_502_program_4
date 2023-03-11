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
   /**
    * @brief Constructs an empty Inventory object.
    *
    * @pre None.
    * @post An empty Inventory object is created.
    */
   Inventory();

   /**
    * @brief Destructor for the Inventory class.
    *
    * Pre-condition: An Inventory object has been instantiated.
    *
    * Post-condition: All dynamically allocated memory for Coin, Comic, Sport, Customer, and Transaction objects
    * has been freed, and the Inventory object has been destroyed.
    *
   */
   ~Inventory();

   /**
    * Read inventory from a given file path.
    *
    * @param path The path to the input file.
    * @return Returns 0 on success, -1 on error.
    *
    * @pre The input file at the given path exists.
    * @post The items in the input file have been added to the inventory.
    */
   int readInventory(string path);

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
   int readCustomer(string path);

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
   int parseCommands(string path);

   /**
    * Find a customer in the inventory by their ID.
    *
    * @param id The ID of the customer to find.
    * @return A pointer to the customer object if found, NULL otherwise.
    *
    * Pre-conditions:
    * - The inventory must contain at least one customer object.
    * - The ID parameter must not be empty or null.
    *
    * Post-conditions:
    * - If a customer object with the given ID is found in the inventory, a pointer to that object is returned.
    * - If a customer object with the given ID is not found in the inventory, NULL is returned.
    * - The state of the inventory is not modified by this method.
    */
   Customer* findCustomer(string id);

   /**
    * Finds an item in the Inventory based on its type and attributes.
    *
    * @param item A pointer to the item to find.
    * @return Returns a pointer to the item if found, or NULL if not found.
    *
    * @pre The Inventory object must be initialized with valid data and items.
    * @post None.
    *
    * This method first calls the findItems method to get a vector of items of the same type as the item to be found.
    * It then iterates through the vector to find an item that matches the given item's attributes using the compare method.
    * If found, a pointer to the matching item is returned. If not found, NULL is returned.
    */
   Item* findItem(Item* item);

   /**
    * Returns a pointer to a vector containing all items of the specified type.
    *
    * @param type The type of items to search for. 'M' for coins, 'C' for comics, or 'S' for sports.
    * @return Returns a pointer to a vector containing all items of the specified type, or NULL if the type is invalid.
    *
    * @pre The Inventory object must be initialized with valid data and items.
    * @post Returns a pointer to a vector containing all items of the specified type, or NULL if the type is invalid.
    */
   vector<Item*>* findItems(char type);

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
   void displayForCustomer(string id);

   /**
    * Displays the current inventory of items in the console.
    *
    * @pre The Inventory object must be initialized with valid data and items.
    * @post The current inventory of items is displayed in the console.
    */
   void displayInventory();

   /**
    * Displays the transaction history of all customers in the inventory,
    * sorted alphabetically by customer name and then chronologically by transaction date.
    *
    * @pre The Inventory object must be initialized with valid data and items.
    * @post The transaction history of all customers in the inventory is printed to the console.
    *       Transactions are sorted by customer name and then by transaction date.
    */
   void displayHistory();

public:

   
};

