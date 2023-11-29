#ifndef ROOM
#define ROOM

#include <iostream>
#include <cstring>
#include "room.h"
#include <vector>
#include <map>

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
private:
  const char* info;
  map<const char*, Room*> exits;
  vector<Item*> items;
};

#endif

