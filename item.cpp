#include <iostream>
#include "item.h"
#include <cstring>

using namespace std;

void item::setName(char* outName){
	strcpy(name, outName);
}

void item::getName(char* outName){
	strcpy(outName, name);
}

void item::print(){
	cout << name << endl;
}
