#include <iostream>
#include <cstring>
#include "room.h"
#include "item.h"
#include <vector>
#include <map>

//I saw we needed maps so I used this to learn how to use it
//https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/

using namespace std;

const int SIZE = 80;
char c_input[SIZE];
int main() {
  vector<Item*> playerInventory;
  bool play = true;
  while(play) {
    currentRoom->printinfo();
    cout << "Enter what you want to do: (GRAB, MOVE, or QUIT)" << endl;
    cin >> c_input;
    if(strcmp(c_input, "GRAB") == 0) {
      char itemGrab[SIZE];
      cout << "Enter the name of the item you wish to grab: " << endl;
      cin >> itemGrab;
      if(currentRoom->item_pres(itemGrab)) {
	Item* grabbedItem = currentRoom->Pickup(itemGrab);
	playerInventory.push_back(grabbedItem);
	cout << "You picked up: " << grabbedItem->getName() << endl;
	// Win conditon = pickup all 5 items
	if(playerInventory.size() == 5) {
	  cout << "You have picked up all the items in this house, you won. Good job." << endl;
	  play = false;
	}
      }
      else {
	cout << "There is no item with that name in this room, maybe you spell it wrong. " << endl;
      }
    }
    else if(strcmp(c_input, "MOVE") == 0) {
      char direction[SIZE];
      cout << "Enter what direction you want to move (North, East, South, West): " << endl;
      cin >> direction;
      if (currentRoom->getExits().count(direction) > 0) {
	currentRoom = currentRoom->getExits().at(direction);
	cout << "You move this direction: " << direction << endl;
      }
      else {
	cout << "This direction is not valid. Try again(check spelling)" << endl;
      }
    }
    else if(strcmp(c_input, "QUIT") == 0) {
      play = false;
    }
  }
}
