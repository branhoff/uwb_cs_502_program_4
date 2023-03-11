#include "Customer.h"

/**
 * @brief Creates a new Customer object with the given ID, first name, and last name.
 *
 * @pre None.
 *
 * @post A new Customer object is created with the given ID, first name, and last name.
 *
 * @param id The unique ID of the customer.
 * @param fname The first name of the customer.
 * @param lname The last name of the customer.
 *
 * @return None.
 */
Customer::Customer(string id, string fname, string lname)
{
   this->id = id;
   this->firstName = fname;
   this->lastName = lname;
}