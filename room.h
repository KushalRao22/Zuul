#include <iostream>
#include <cstring>
#include <vector>
#include "item.h"
#include <map>

using namespace std;

class room{
	public:
	void addItem(char* outName);
	void setName(char* outName);
	vector<item*> roomItems;
	char name[265];
	char charInput[256];
        void getName(char* charInput);
        void setExit(char* dir, room* exitRoom);
        void getExit(char* dir, room* cRoom);
        map<char*, room*> mymap;
        map<char*, room*>::iterator it = mymap.begin();
	void givePlayerItems(vector<item*>& playerInventory, char* outName);
};



