/*
This is a file to hold items for the game Zuul.

Last modified: 12/19/21

By: Kushal Rao
*/
//Imports
#include <iostream>
#include "item.h"
#include <cstring>

using namespace std;

void item::setName(char* outName){//Set name of the item
  strcpy(name, outName);
}

void item::getName(char* outName){//Get name of the item
  strcpy(outName, name);
}

void item::print(){//Print the name of the item
  cout << name << endl;
}
