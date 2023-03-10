#pragma once

#include <string>


class Item {
public:
   Item(char type, int year, int grade);

   virtual std::string getInfo();

   virtual bool compare(Item* other) = 0;

protected:
   char type;
   int year;
   int grade;
};
