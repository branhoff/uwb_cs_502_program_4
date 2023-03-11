//--------------------------------------------------------------------
// CUSTOMER.CPP
// Implementation of the Customer class
// Author: Brandon Hoffman
//--------------------------------------------------------------------
// Customer class:
//   Represents a customer in the inventory management system.
//   Contains the following methods:
//      Customer - constructor that initializes a new customer with the given ID, first name, and last name.
//      ~Customer - destructor that deallocates memory used by the customer
//      getId - retrieves the ID of the customer
//      getFirstName - retrieves the first name of the customer
//      getLastName - retrieves the last name of the customer
//   Assumptions:
//      - The customer ID is unique
//--------------------------------------------------------------------

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
Customer::Customer(string id, string fname, string lname) {
   this->id = id;
   this->firstName = fname;
   this->lastName = lname;
}

string Customer::getId() {
   return this->id;
}

string Customer::getFullName() {
   return this->firstName + " " + this->lastName;
}