#include "Item.h"


Item::Item(char type, int year, int grade) {
   this->type = type;
   this->year = year;
   this->grade = grade;
}

std::string Item::getInfo() {
   return "";
}