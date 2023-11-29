//code for item.h
#ifndef ITEM
#define ITEM
//adding includes
#include <iostream>
#include <cstring>

using namespace std;

class Item {
public:
  Item(char* name);
  char* getName();

private:
  char* name;
};

#endif
