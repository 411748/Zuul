#include <iostream>
#include <cstring>
#include "room.h"

using namespace std;

Room::Room(const char* info) : info(info) {
  
}

void Room::Exits(Room* North, Room* East, Room* South, Room* West) {
  exits["North"] = North;
  exits["East"] = East;
  exits["South"] = South;
  exits["West"] = West;
}

void Room::Items(Item* item) {
  items.push_back(item);
}

void printinfo() {
  cout << "You are currently in: " << info << endl;
  cout << "You can move in these directions: " << endl;
  for (auto it = exits.begin(); it != exits.end(); ++it) {
    cout << it->first << endl;
  }
  if(!items.empty){
    cout << "The items you can pick up are: " << endl;
    for(auto it = itmes.begin(); it != items.end(); ++it) {
      cout << (*it)->getName() << endl;
    }
  }
  else {
    cout << "There are no items for you to pickup in this room" << endl;
  }
}

bool Room:item_pres(const char* itemName) {
  for(auto it = items.begin(); it!= items.end(); ++it) {
    if(strcmp((*it)->getName(), itemName) == 0) {
      return true;
    }
  }
  return false;
}

void Room::Pickup(const char* itemName) {
  for(auto it = items.begin(); it != items.end(); ++it) {
    if(strcmp((*it)->getName(), itemName) == 0) {
      Item* item = *it;
      items.earse(it);
      return item;
    }
  }
}


