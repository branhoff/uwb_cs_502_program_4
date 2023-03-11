# Collectibles store simulation

A local collectibles store wishes to automate their inventory tracking system. Three types of items are to be tracked:

- Coins
- Comic books
- Sports cards
Customer transactions (buy/sell) are also to be tracked. Five types of actions are desired in the system:

- Sell: removes an item from the store inventory
- Buy: adds an item to the store inventory
- Display: outputs the entire inventory of the store, including the number of each item in inventory
- Customer: outputs all of the transactions for a customer (in chronological order), including the item
- History: outputs the history for every customer, with the customers in alphabetical order.
You will design and implement a program that will initialize the contents of the inventory from a file, the customer list from another file, and process an arbitrary sequence of commands from a third file.

 

## Details

All coins have type, year, and grade (an integer). All comic books have a title, publisher, year, and grade (a string). All sports cards have a player, a manufacturer, a year, and a grade (a string). For Display output, the items in the inventory are sorted as follows:

- Coins are sorted first by type, then by year, then by grade
- Comics are sorted first by publisher, then by title, then by year, then by grade
- Sports cards are sorted by player, then by year, then by manufacturer, then by grade
You can assume that each item is uniquely identified by the complete set of sorting criteria. To facilitate processing of the files, Coins are marked `‘M’`, comics are marked `‘C’`, and sports cards are marked `‘S’`.

The data file for initialization of the inventory lists each item on a separate line with a character denoting the type of item, number in inventory, year, grade, type/title/player, publisher/manufacture (if necessary). Fields are separated by commas as follows:
```
  M, 3, 2001, 65, Lincoln Cent
  M, 10, 1913, 70, Liberty Nickel
  C, 1, 1938, Mint, Superman, DC 
  C, 2, 2010, Excellent, X-Men, Marvel
  Z, 4, 1986, Raging, Metallica, Master of Puppets
  S, 9, 1989, Near Mint, Ken Griffey Jr., Upper Deck
  S, 1, 1952, Very Good, Mickey Mantle, Topps
```
You may assume correct formatting, but the data could be invalid. In this data, the `‘Z’` code is an invalid entry.

Customer information is stored in a similar file. Customers have a 3-digit ID number that uniquely identifies them:
```
  001, Serena Williams
  456, Keyser Soze
  999, Pele
```
You can assume that this data is formatted correctly, but not that there will be exactly two names. (Go ahead and sort by first name, if that is first in the file.)

Your code will be tested using a third file containing the commands (`S` for Sell, `B` for Buy, `D` for Display, `C` for Customer, and `H` for History). Except for the Display and History commands, the second field is customer ID. For buy and sell commands, the third field is the item type and the remaining fields are the item.
```
  S, 001, S, 1989, Near Mint, Ken Griffey Jr., Upper Deck
  B, 456, M, 1913, 70, Liberty Nickel
  C, 999
  D
  X, 999, Z, 1986, Raging, Metallica, Master of Puppets
  S, 000, Q, 2112, Gnarly, Windows, Microsoft
  H
```
Once again, the data will be formatted correctly, but may include errors. You should check to make sure that the number of each item in the inventory doesn’t go below zero. Do not print output for successful buy or sell commands, but do print error messages for incorrect data. Output for your Display, Customer, and History commands should be neatly formatted with one line per item/transaction. The inventory (Display command) should output all coins, then all comics, then all sports cards (sorted as specified above within each type).

## Forward declarations

Be careful about circular #include dependencies. These will not compile correctly. For example, you may want to #include "Customer.h" in Item.h and #include "Item.h" in Customer.h. This cannot be done. It may even yield misleading compiler errors. If both classes need to know about each other (not necessarily the case for Customer and Item), then you should use a forward reference. For example, in Customer.h, you can use:

  class Item;

This would allow the `Customer` class to know that there is an `Item` class and even to have a pointer to an `Item` in the private data, without knowing the specific details of the `Item` class in the header file. The `Customer.cpp` file can `#include "Item.h"`, since this doesn't yield a cycle of includes.

## File input
We haven't looked at file I/O much, but you need to do a bit more for this assignment. While you can certainly find documentation online and in the book, I thought I might let you know what I think some of the more useful methods are (or at least how I would do things).

First, create an input filestream:
```
#include <fstream>

string inventoryFile = "hw4inventory.txt";
ifstream input(inventoryFile);
```
One strategy would be to loop as long as the file has data and get a line to parse with your code:
```
while(invStream.peek() != EOF) {
    string fileInput;
    getline(inventoryStream, fileInput);
    // Do something to parse the line of input here
}
```
Another strategy would be to parse the file stream piece-by-piece. The most useful methods for this are probably `get()`, `getline()`, `ignore()`, and `operator>>`. For example, you can do something like:

	if (invStream.eof()) break;
	getline(invStream, type, ','); 		//get type of inventory
	invStream.get(); 			//discard space 
	getline(invStream, stringCount, ','); 	//get count
	intCount = atoi(stringCount.c_str());
	invStream.get(); 			//discard space
	getline(invStream, description, '\n'); 	//get rest of info
With the above syntax, the third parameter is a delimiter. You will only get characters until the delimiter is reached. You can also use ignore to throw away characters (like commas):

	invStream.ignore();	        //throw away a character
	invStream.ignore(n, delimiter);	//throw away n chars, unless delimiter found


## Hash tables

You are required to use at least one hash table in your program (we'll cover these soon). There are actually several places where they could be used. If you want to get started designing with them, the important aspect of hash tables is that they are used for fast lookup of items. For example, if each item can be mapped into a unique number, you can use an array to store the items according to their unique number and look them up in O(1) time. Hash tables usually waste some memory, since not all of the array will be filled. However, the waste is not too bad, if you store pointers to items, rather than the items themselves. It is generally better to use a hash table than a switch statement (or if-then-else-if) when there are several cases that must be tested to determine which function to call. (If you aren't using a factory with hashed dummy objects in your design, then your design could be improved.) Note: your implementation will implement any hash tables from scratch (do not use STL, except perhaps a vector for this).