//Main check
#include<iostream>
#include<cstring>
#include "item.h"
#include "room.h"
#include <vector>

using namespace std;

void intialize();

int main(){
  bool play = true;
  cout << "Welcome to Zuul"<< endl;
  char input[265];
  char print[265];
  vector<item*> Inventory;

  //Intialize Everything
  //Create Variables for Directions
  char* east = (char*)("East");
  char* west = (char*)("West");
  char* north = (char*)("North");
  char* south = (char*)("South");

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
  
  office->addItem((char*)("Robot"));
  nurse->addItem((char*)("Backpack"));
  math_class->addItem((char*)("Math Textbook"));
  science_lab->addItem((char*)("Science Textbook"));
  cafeteria->addItem((char*)("Lunch Bag"));
  
  room* CurrentRoom = outside;

  while(play){
    CurrentRoom->printDis(print);
    cout << "What do you want to do(Move, Inventory, Get, Drop, Quit)"<< endl;
    cin >> input;
    if(strcmp(input, "Inventory")== 0){
      cout << "Inventory:" << endl;
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

void intialize(){
}
