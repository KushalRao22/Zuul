/*
This is a .h file for item.cpp

Last modified: 12/19/21

By: Kushal Rao
*/

//Imports
#include <iostream>
#include <cstring>

//Header Gaurd
#ifndef ADD_H
#define ADD_H

using namespace std;

class item{
public:
  void setName(char* outName);//Set name of item
  void getName(char* outName);//Get name of item
  void print();//Print item
  char name[265];//Variable to hold name
};
#endif


