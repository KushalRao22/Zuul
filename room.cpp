#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"
#include <map>

using namespace std;

void room::addItem(char* outName){
	item* n = new item();
	n->setName(outName);
	roomItems.push_back(n);
}
void room::setName(char* outName){
	strcpy(name, outName);
	cout << name << endl;
}
void room::getName(char* charInput){
	strcpy(charInput, name);
}
void room::givePlayerItems(vector<item*>& playerInventory, char* outName){
	for(int i = 0; i < roomItems.size(); i++){
		roomItems[i]->getName(charInput);
		if(strcmp(outName, charInput)== 0){
		  playerInventory.push_back(roomItems[i]);
			roomItems.erase(roomItems.begin() +i);			
		}

	}
}
void room::takePlayerItems(vector<item*>& playerInventory, char* outName){
	for(int i = 0; i < playerInventory.size(); i++){
		playerInventory[i]->getName(charInput);
		if(strcmp(outName, charInput)== 0){
		  roomItems.push_back(playerInventory[i]);
			playerInventory.erase(playerInventory.begin() +i);			
		}

	}
}
void room::setExit(char* dir, room* exitRoom){
  mymap.insert(pair<char*, room*>(dir, exitRoom));
}

void room::getExit(char* dir, room*& cRoom){
  for(it = mymap.begin(); it != mymap.end(); ++it){
    if(strcmp(dir, it->first) == 0){
      cRoom = it->second;
    }
  }
}
