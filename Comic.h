#pragma once

#include "Item.h"


class Comic : public Item {

public:
   Comic(int year, string grade, string title, string publisher);

   virtual std::string getInfo() override;

   virtual int compare(Item* other) override;

private:
   std::string title;
   std::string publisher;
};

