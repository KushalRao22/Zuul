/*
This is a class for all the rooms in the zuul game.

Last modified: 12/19/21

By: Kushal Rao
*/

//Imports
#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"
#include <map>

using namespace std;

void room::addItem(char* outName){//Adds a new item to the room
  item* n = new item();
  n->setName(outName);
  roomItems.push_back(n);//Add item to vector of items in the room
}

void room::setName(char* outName){//Set name of the room
  strcpy(name, outName);
}

void room::getName(char* charInput){//Get name of the room
  strcpy(charInput, name);
}

void room::givePlayerItems(vector<item*>& playerInventory, char* outName){//Player picks up an item
  for(int i = 0; i < roomItems.size(); i++){//Search vector for specific item
    roomItems[i]->getName(charInput);
    if(strcmp(outName, charInput)== 0){//If the item is the one user wants to pick up
      playerInventory.push_back(roomItems[i]);//Add the item to player inventory
      roomItems.erase(roomItems.begin() +i);//Remove item from the rooms vector
    }
  }
}

void room::takePlayerItems(vector<item*>& playerInventory, char* outName){//Player drops an item
  for(int i = 0; i < playerInventory.size(); i++){//Search for specific Item
    playerInventory[i]->getName(charInput);
    if(strcmp(outName, charInput)== 0){//If the item is found
      roomItems.push_back(playerInventory[i]);//Add item to the room
      playerInventory.erase(playerInventory.begin() +i);//Remove item from player inventory
    }
  }
}

void room::setExit(char* dir, room* exitRoom){//Set exit for the room
  mymap.insert(pair<char*, room*>(dir, exitRoom));
}

void room::getExit(char* dir, room*& cRoom){//Move
  for(it = mymap.begin(); it != mymap.end(); ++it){//Look until you find the right direction you want to go to
    if(strcmp(dir, it->first) == 0){
      cRoom = it->second;//Change current room to new room
    }
  }
}

void room::printDis(char* print){//Print exits, items and name
  cout << "Current Room: " << name << endl;//Print name
  cout << "Items:";//Print all the items
  if(roomItems.size() > 0){//Print all the items
    for(int i = 0; i < roomItems.size(); i++){
      roomItems[i]->getName(print);
      cout << " " << print << endl;
    }
  }
  else{
    cout << " No Items" << endl;//If there are no items print No items
  }
  cout << "These Are the Exits:" << endl;//List exits
  for(it = mymap.begin(); it != mymap.end(); ++it){//Print directions if they are there
   if(strcmp("North", it->first) == 0){
     cout << "North ";
   }
   if(strcmp("East", it->first) == 0){
     cout << "East ";
   }
   if(strcmp("South", it->first) == 0){
     cout << "South ";
   }
   if(strcmp("West", it->first) == 0){
     cout << "West ";
   }
  }
  cout << endl << endl;
}
