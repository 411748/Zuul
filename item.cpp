//code for item.cpp
//adding includes for the header file 
#include <iostream>
#include <cstring>
#include "item.h"
 
using namespace std;
//Finding name of item and copying
Item::Item(char* newName){
  name = new char[80];
  strcpy(name, newName);
}

char* Item::getName()  {
    return name;
}
