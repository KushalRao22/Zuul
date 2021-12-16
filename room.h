#include <iostream>
#include <cstring>
#include <vector>
#include "item.h"

using namespace std;

class room{
	public:
	void addItem(char* outName);
	void setName(char* outName);
	vector<item*> roomItems;
	char name[265];
	char charInput[256];
	void getName(char* charInput);
	void givePlayerItems(vector<item> playerInventory, char* outName);
};



