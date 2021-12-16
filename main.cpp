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
	vector<item> Inventory;
	room* outside = new room();
	outside->setName("Outside");	
	outside->addItem("comp");
	room* CurrentRoom = outside;
	while(play){
	cout << "What do you want to do(Move, Inventory, Get, Drop, Quit)"<< endl;
	cin >> input;
	if(strcmp(input, "Inventory")== 0){
}
	if(strcmp(input, "Move") == 0){
	
}
	if(strcmp(input, "Get") == 0){
		cout << "What is the name of the item you want to get?" << endl;
		cin >> input;
		CurrentRoom->givePlayerItems(Inventory, input;)
}
	if(strcmp(input, "Drop") == 0){

}
	if(strcmp(input, "Quit") == 0){
		play = false;
}
	
}
	return 0;

}

