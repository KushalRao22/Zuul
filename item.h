#include <iostream>
#include <cstring>

#ifndef ADD_H
#define ADD_H

using namespace std;

class item{
	public:
	void setName(char* outName);
	void gerName(char* outName);
	void print();
	char name[265];
};
#endif


