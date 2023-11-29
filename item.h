#ifndef ITEM
#define ITEM

#include <iostream>
#include <cstring>

using namespace std;

class Item {
public:
  Item(const char* name) : name(name) {}
  const char* getName() const { return name; }

private:
  const char* name;
};

#endif
