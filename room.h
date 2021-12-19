/*
This is the .h file for room.cpp

Last modified: 12/19/21

By:Kushal Rao
*/

//Imports
#include <iostream>
#include <cstring>
#include <vector>
#include "item.h"
#include <map>

using namespace std;

class room{
public:
  vector<item*> roomItems;//Vector for if the room has items in it
  char name[265];//Name of the room
  char charInput[256];//Input
  map<char*, room*> mymap;//Map to keep track of exits
  map<char*, room*>::iterator it = mymap.begin();//Iterator for the map to check exits when moving
  void addItem(char* outName);//Create an item into the room
  void setName(char* outName);//Set the name of the room
  void printDis(char* print);//Print all exits and items and room name
  void getName(char* charInput);//Get name back to main.cpp
  void setExit(char* dir, room* exitRoom);//Set an exit for the room
  void getExit(char* dir, room*& cRoom);//Move into an exit
  void givePlayerItems(vector<item*>& playerInventory, char* outName);//Player picks up a item
  void takePlayerItems(vector<item*>& playerInventory, char* outName);//Player drops an item
};



