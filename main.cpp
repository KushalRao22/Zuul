/*
This is a class that lets you play Zuul and holds all rooms and inventory of player. Uses both room.cpp and item.cpp

Last modified: 12/19/21

By: Kushal Rao
*/
//Imports
#include<iostream>
#include<cstring>
#include "item.h"
#include "room.h"
#include <vector>

using namespace std;

void intialize();

int main(){
  //Intialize Variables
  bool play = true;
  char input[265];
  char print[265];
  char itemName1[265];
  char itemName2[256];
  vector<item*> Inventory;

  //Intialize Everything
  //Create Variables for Directions
  char* east = (char*)("East");
  char* west = (char*)("West");
  char* north = (char*)("North");
  char* south = (char*)("South");

  //Create Rooms
  room* outside = new room();
  outside->setName((char*)("Outside"));
  room* computer_lab = new room();
  computer_lab->setName((char*)("Computer Lab"));
  room* theatre = new room();
  theatre->setName((char*)("Theatre"));
  room* office = new room();
  office->setName((char*)("Office"));
  room* cafeteria = new room();
  cafeteria->setName((char*)("Cafeteria"));
  room* nurse = new room();
  nurse->setName((char*)("Nurse's Office"));
  room* west_bathroom = new room();
  west_bathroom->setName((char*)("West Bathroom"));
  room* lockers = new room();
  lockers->setName((char*)("Locker Room"));
  room* gym = new room();
  gym->setName((char*)("Gym"));
  room* east_bathroom = new room();
  east_bathroom->setName((char*)("East Bathroom"));
  room* library = new room();
  library->setName((char*)("Library"));
  room* science_lab = new room();
  science_lab->setName((char*)("Science Lab"));
  room* math_class = new room();
  math_class->setName((char*)("Math Class"));
  room* literature_class = new room();
  literature_class->setName((char*)("English Class"));
  room* south_bathroom = new room();
  south_bathroom->setName((char*)("South Bathroom"));

  // Initialize room exits
  //outside
  outside->setExit(east, theatre);
  outside->setExit(south, computer_lab);
  //Theater
  theatre->setExit(west, outside);
  //Computer Lab
  computer_lab->setExit(north , outside);
  computer_lab->setExit(east, office);
  computer_lab->setExit(south, lockers);
  computer_lab->setExit(west, cafeteria);
  //Office
  office->setExit(west, computer_lab);
  office->setExit(east, nurse);
  office->setExit(south, gym);
  //cafeteria
  cafeteria->setExit(east, computer_lab);
  cafeteria->setExit(south, west_bathroom);
  //nurse
  nurse->setExit(west, office);
  //west bathroom
  west_bathroom->setExit(east, lockers);
  west_bathroom->setExit(north , cafeteria);
  //lockers
  lockers->setExit(east, gym);
  lockers->setExit(south, library);\
  lockers->setExit(west, west_bathroom);
  lockers->setExit(north , computer_lab);
  //gym
  gym->setExit(west, lockers);
  gym->setExit(south, east_bathroom);
  gym->setExit(north , office);
  //east bathroom
  east_bathroom->setExit(north , gym);
  //library
  library->setExit(north , lockers);
  library->setExit(south, literature_class);
  library->setExit(west, science_lab);
  //science lab
  science_lab->setExit(south, math_class);
  science_lab->setExit(east, library);
  //math class
  math_class->setExit(north , science_lab);
  math_class->setExit(east, literature_class);
  //literature class
  literature_class->setExit(north , library);
  literature_class->setExit(south, south_bathroom);
  literature_class->setExit(west, math_class);
  //south bathroom
  south_bathroom->setExit(north , literature_class);

  //Add Items
  office->addItem((char*)("Robot"));
  nurse->addItem((char*)("Backpack"));
  math_class->addItem((char*)("Math_Textbook"));
  science_lab->addItem((char*)("Science_Textbook"));
  cafeteria->addItem((char*)("Lunch_Bag"));
  
  room* CurrentRoom = outside;

  cout << "Welcome to Zuul"<< endl;//Welcome Player to the game

  while(play){//While user wants to play
    CurrentRoom->printDis(print);//Print 
    cout << "What do you want to do (Move, Inventory, Get, Drop, Quit)"<< endl;//What does the User want to do
    cin >> input;
    if(strcmp(input, "Inventory")== 0){//If Player wants to check Inventory
      cout << "Inventory:" << endl;
      if(Inventory.size() > 0){
	for(int i =0; i < Inventory.size(); i++){
	  Inventory[i]->getName(print);//Print all the names of the Items in Inventory
	  cout << print << endl;
	}
      }
      else{
	cout << "No Items" << endl;//If no items say no items
      }
    }
    if(strcmp(input, "Move") == 0){//If user wants to move
      cout << "North, East, South, or West?" << endl;
      cin >> input;
      CurrentRoom->getExit(input, CurrentRoom);//Change room
    }
    if(strcmp(input, "Get") == 0){//Grab Item from room
      cout << "What is the name of the item you want to get?" << endl;
      cin >> input;
      CurrentRoom->givePlayerItems(Inventory, input);//Call get item in the room
    }
    if(strcmp(input, "Drop") == 0){//Drop Item into a room
      cout << "What is the name of the item you want to drop" << endl;
      cin >> input;
      CurrentRoom->takePlayerItems(Inventory, input);//Call drop item in the room
    }
    if(strcmp(input, "Quit") == 0){//If user wants to quit
      play = false;//stop the wile loop
    }
    else{
      cout << endl;
    }
    if(CurrentRoom == lockers){//Win condition, In the locker room and have backpack and Math Textbook
      for(int i = 0; i < Inventory.size(); i++){
	for(int j = 0; j < Inventory.size(); j++){
	  Inventory[i]->getName(itemName1);
	  Inventory[j]->getName(itemName2);
	  if(strcmp(itemName1, "Backpack") && strcmp(itemName2, "Math_Textbook")){//If user had both a backpack and math textbook
	    cout << "You Win" << endl << "Thanks for playing" << endl;
	    play = false;//End game
	  }
	}
      }
    }
  }
  return 0;
}


