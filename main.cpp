//Main check
#include<iostream>
#include<cstring>
#include "item.h"
#include "room.h"
#include <vector>

using namespace std;

int main(){
	bool play = true;
	cout << "Welcome to Zuul"<< endl;
	char input[265];
	char print[265];
	vector<item*> Inventory;
	room* outside = new room();
	outside->setName("Outside");	
	outside->addItem("comp");
	room* CurrentRoom = outside;
	room* inside = new room();
	inside->setName("Inside");
	char* east = (char*)("East");
	char* west = (char*)("West");
	inside->setExit(west, outside);
	outside->setExit(east, inside);
	while(play){
	cout << "What do you want to do(Move, Inventory, Get, Drop, Quit)"<< endl;
	CurrentRoom->getName(print);
	cout << print << endl;
	cin >> input;
	if(strcmp(input, "Inventory")== 0){
	  for(int i =0; i < Inventory.size(); i++){
	    Inventory[i]->getName(print);
	    cout << print << endl;
	  }
}
	if(strcmp(input, "Move") == 0){
	  cout << "North, East, South, or West?" << endl;
	  cin >> input;
	  CurrentRoom->getExit(input, CurrentRoom);
}
	if(strcmp(input, "Get") == 0){
		cout << "What is the name of the item you want to get?" << endl;
		cin >> input;
		CurrentRoom->givePlayerItems(Inventory, input);
}
	if(strcmp(input, "Drop") == 0){
	  cout << "What is the name of the item you want to drop" << endl;
	  cin >> input;
	  CurrentRoom->takePlayerItems(Inventory, input);
}
	if(strcmp(input, "Quit") == 0){
		play = false;
}
	
}
	return 0;

}

