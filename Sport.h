#pragma once
#include "Item.h"
class Sport :    public Item
{
public:
   Sport(int year, string grade, string player, string manufacturer);

   virtual std::string getInfo() override;

   virtual int compare(Item* other) override;
private:
   string player;
   string manufacturer;
};

