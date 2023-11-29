//code for room.cpp
//adding all my includes
#include <iostream>
#include <cstring>
#include "room.h"
//Worked together with ghazi for a lot of room code
using namespace std;

Room::Room(const char* info) : info(info) {}
//Exit function
void Room::Exits(Room* North, Room* East, Room* South, Room* West) {
  exits["North"] = North;
  exits["East"] = East;
  exits["South"] = South;
  exits["West"] = West;
}
//Adding items to specific rooms
void Room::Items(Item* item) {
  items.push_back(item);
}
//print function
void Room::printinfo() {
  cout << "You are currently in: " << info << endl;
  cout << "You can move in these directions: " << endl;
  for (auto it = exits.begin(); it != exits.end(); ++it) {
    if(it->second != NULL) {
      cout << it->first << endl;
    }
  }
  if (!items.empty()) {
    cout << "The items you can pick up are: " << endl;
    for (auto it = items.begin(); it != items.end(); ++it) {
      cout << (*it)->getName() << endl;
    }
  } else {
    cout << "There are no items for you to pick up in this room" << endl;
  }
}
//checking if items are present function
bool Room::item_pres(const char* itemName) {
  for (auto it = items.begin(); it != items.end(); ++it) {
    if (strcmp((*it)->getName(), itemName) == 0) {
      return true;
    }
  }
  return false;
}
//Finding if exit is true for that specific room
Room* Room::getExit(char* in) {
  if(strcmp(in, "North") == 0) {
    return exits["North"];
  }
  else if(strcmp(in, "East") == 00) {
    return exits["East"];
  }
  else if(strcmp(in, "South") == 0) {
    return exits["South"];
  }
  else if(strcmp(in, "West") == 0) {
    return exits["West"];
  }
  else {
    return NULL;
  }
}

Item* Room::Pickup(const char* itemName) {
  for (auto it = items.begin(); it != items.end(); ++it) {
    if (strcmp((*it)->getName(), itemName) == 0) {
      Item* item = *it;
      items.erase(it);
      return item;
    }
  }
  return nullptr; // Return nullptr if the item is not found
  // https://www.geeksforgeeks.org/understanding-nullptr-c/
}
