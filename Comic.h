//--------------------------------------------------------------------
// COMIC.H
// Declaration of the Comic class
// Author: Brandon Hoffman
//--------------------------------------------------------------------
// Comic class:
// Represents a comic item in a store inventory management system.
// Inherits from the Item class and adds the following methods:
// Comic - constructor that initializes the year, grade, title, and publisher of the comic item
// getInfo - returns a string representation of the comic item, including title, year, grade, and publisher
// compare - compares two comic items based on their sorting criteria
// Assumptions:
// - The year input is a positive integer
// - The grade, title, and publisher inputs are non-empty strings
//--------------------------------------------------------------------

#pragma once

#include "Item.h"


class Comic : public Item {

public:
   /**
    * @brief Constructor for the Comic class to initialize the data members.
    *
    * @param year The year the comic book was published.
    * @param grade The grade of the comic book.
    * @param title The title of the comic book.
    * @param publisher The publisher of the comic book.
    *
    * @pre year is a positive integer.
    *      grade is a non-empty string.
    *      title is a non-empty string.
    *      publisher is a non-empty string.
    *
    * @post The year, grade, title, and publisher data members are initialized with the input values.
    */
   Comic(int year, string grade, string title, string publisher);

   /**
    * @brief Returns a string containing the information about the comic.
    *
    * @pre None.
    *
    * @post A string containing the title, year, grade, and publisher of the comic is returned.
    *
    * @return A string containing the title, year, grade, and publisher of the comic.
    */
   virtual std::string getInfo() override;

   /**
    * @brief Compares two comic books based on their sorting criteria.
    *
    * @pre None.
    *
    * @post Returns -1 if this comic book should come before the other comic book in the sorting order,
    *       0 if they are equal, and 1 otherwise.
    *
    * @param other The other comic book to compare to.
    *
    * @return -1 if this comic book should come before the other comic book in the sorting order,
    *         0 if they are equal, and 1 otherwise.
    */
   virtual int compare(Item* other) override;

private:
   std::string title;
   std::string publisher;
};

