// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

#include "Inventory.h"

int main() {
   Inventory inventory;
   inventory.readInventory("hw4inventory.txt");
   inventory.readCustomer("hw4customers.txt");
   inventory.parseCommands("hw4commands.txt");

   return 0;
}
