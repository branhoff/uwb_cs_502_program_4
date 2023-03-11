#include "Comic.h"

Comic::Comic(int year, string grade, std::string title, std::string publisher)
   : Item('C', year, grade), title(title), publisher(publisher) {}

std::string Comic::getInfo() {
   return "Comic: " + title + " (" + std::to_string(year) + "), Grade: " + grade + ", Publisher: " + publisher;
}

int Comic::compare(Item* other) {
   Comic* otherComic = dynamic_cast<Comic*>(other);
   if (otherComic == nullptr) {
      return -1;
   }

   if (publisher < otherComic->publisher) 
      return -1;
   if (publisher > otherComic->publisher)
      return 1;

   if (title < otherComic->title)
      return -1;
   if (title > otherComic->title)
      return 1;

   if (year < otherComic->year)
      return -1;
   if (year > otherComic->year)
      return 1;

   if (grade < otherComic->grade)
      return -1;
   if (grade > otherComic->grade)
      return 1;

   return 0;
}