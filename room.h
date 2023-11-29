#ifndef ROOM
#define ROOM

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "item.h"

using namespace std;

class Item;

class Room {
public:
  Room(const char* info);
  void Exits(Room* North, Room* East, Room* South, Room* West);
  void Items(Item* item);
  void printinfo();
  bool item_pres(const char* itemName);
  Item* Pickup(const char* itemName);
  Room*getExit(char* in);
private:
  const char* info;
  map<const char*, Room*> exits;
  vector<Item*> items;
};

#endif


