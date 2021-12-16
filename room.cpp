#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"

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
void room::givePlayerItems(vector<item> playerInventory, char* outname){
	for(int i = 0; i < roomItems.size(); i++){
		roomItems(i)->getName(charInput);
		if(strcmp(outName, charInput)== 0){
			playInventory.push_back(roomItems[i]);
			roomItems.eraase(roomItems.gegin() +i);			
		}

	}
}




