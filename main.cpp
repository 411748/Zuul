//Nick Braun
//11/29/2023
//Zuul - Objective is to find and grab all 5 items while moving through different rooms

//Includes
#include <iostream>
#include <cstring>
#include "room.h"
#include "item.h"
#include <vector>
#include <map>

//I saw we needed maps so I used this to learn how to use it
//https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/

using namespace std;

//For all chars
const int SIZE = 200;
char c_input[SIZE];
//Main function
int main() {
  //Keep playing until won or quit
  bool play = true;

  //Adding and descriving all 15 rooms
  char* first_bath_desc = new char[SIZE];
  strcpy(first_bath_desc, "First Bathroom: Very cool place to be. Only the parents of this house should really be here.");
  Room* First_Bathroom = new Room(first_bath_desc);
  char* first_bed_desc = new char[SIZE];
  strcpy(first_bed_desc, "First Bedroom: This is the parents bedroom, you shouldnt be here...");
  Room* First_Bedroom = new Room(first_bed_desc);
  char* first_hall_desc = new char[SIZE];
  strcpy(first_hall_desc, "First Hallway: This is a very cool hallway with wooden floors");
  Room* First_Hallway = new Room(first_hall_desc);
  char * sec_bed_desc = new char[SIZE];
  strcpy(sec_bed_desc, "Second Bedroom: This is the room for the older child, I wonder if they have anything they left around.");
  Room* Second_Bedroom = new Room(sec_bed_desc);
  char* liv_room_desc = new char[SIZE];
  strcpy(liv_room_desc, "Living Room: The family likes to hang around here sometimes.");
  Room* Living_Room = new Room(liv_room_desc);
  char* sec_hall_desc = new char[SIZE];
  strcpy(sec_hall_desc, "Second Hallway:This is a very cool hallway with tiled floors.");
  Room* Second_Hallway = new Room(sec_hall_desc);
  char* t_bed_desc = new char[SIZE];
  strcpy(t_bed_desc, "Third Bedroom: This is where the spoiled younger childs room is. Its very big.");
  Room* Third_Bedroom = new Room(t_bed_desc);
  char* sec_bath_desc = new char[SIZE];
  strcpy(sec_bath_desc, "Second Bathroom: This is the younger childs own bathroom. wow. I wonder if something was left behind here.");
  Room* Second_Bathroom = new Room(sec_bath_desc);
  char* t_hall_desc = new char[SIZE];
  strcpy(t_hall_desc, "Third Hallway: This house has some very epic hallways. This one has carpeted floors.");
  Room* Third_Hallway = new Room(t_hall_desc);
  char* t_bath_desc = new char[SIZE];
  strcpy(t_bath_desc, "Third Bathroom: This is the family bathroom that they all share.");
  Room* Third_Bathroom = new Room(t_bath_desc);
  char* fam_room_desc = new char[SIZE];
  strcpy(fam_room_desc, "Family Room: There is a really big TV in this room. I wonder if that all that there is in here.");
  Room* Family_Room = new Room(fam_room_desc);
  char* kit_desc = new char[SIZE];
  strcpy(kit_desc, "Kitchen: There really are some dangerous items that can be found in a kitchen.");
  Room* Kitchen = new Room(kit_desc);
  char* de_desc = new char[SIZE];
  strcpy(de_desc, "Deck: This deck is massive, there are many chairs, and even a hotub here.");
  Room* Deck = new Room(de_desc);
  char* gar_desc = new char[SIZE];
  strcpy(gar_desc, "Garden: Theres some yummy food here. I wonder if they would share any.");
  Room* Garden = new Room(gar_desc);
  char* pat_desc = new char[SIZE];
  strcpy(pat_desc, "Patio: This is basically just an extention to their deck.");
  Room* Patio = new Room(pat_desc);

  //Setting the exits for these rooms
  First_Bathroom->Exits(NULL, First_Bedroom, NULL, NULL);
  First_Bedroom->Exits(First_Hallway, NULL, NULL, First_Bathroom);
  First_Hallway->Exits(Second_Bedroom, Living_Room, First_Bedroom, NULL);
  Second_Bedroom->Exits(NULL, NULL, First_Hallway, NULL);
  Living_Room->Exits(NULL, Third_Hallway, Second_Hallway, First_Hallway);
  Second_Hallway->Exits(Living_Room, NULL, Third_Bedroom, NULL);
  Third_Bedroom->Exits(Second_Hallway, NULL, Second_Bathroom, NULL);
  Second_Bathroom->Exits(Third_Bedroom, NULL, NULL, NULL);
  Third_Hallway->Exits(Third_Bathroom, Kitchen, Family_Room, Living_Room);
  Third_Bathroom->Exits(NULL, NULL, Third_Hallway, NULL);
  Family_Room->Exits(Third_Hallway, NULL, NULL, NULL);
  Kitchen->Exits(NULL, NULL, Deck, Third_Hallway);
  Deck->Exits(Kitchen, Garden, Patio, NULL);
  Garden->Exits(NULL, NULL, NULL, Deck);
  Patio->Exits(Deck, NULL, NULL, NULL);

  //Adding and naming all 5 items
  char* book_p = new char[SIZE];
  strcpy(book_p, "BOOK");
  Item* book = new Item(book_p);
  char* soap_p = new char[SIZE];
  strcpy(soap_p, "SOAP");
  Item* soap = new Item(soap_p);
  char* board_game_p = new char[SIZE];
  strcpy(board_game_p, "BOARD_GAME");
  Item* board_game = new Item(board_game_p);
  char* knife_p = new char[SIZE];
  strcpy(knife_p, "KNIFE");
  Item* knife = new Item(knife_p);
  char* carrot_p = new char[SIZE];
  strcpy(carrot_p, "CARROT");
  Item* carrot = new Item(carrot_p);

  //Setting items in specific rooms
  Second_Bedroom->Items(book);
  Second_Bathroom->Items(soap);
  Family_Room->Items(board_game);
  Kitchen->Items(knife);
  Garden->Items(carrot);

  //Starting inventory and starting room
  vector<Item*> playerInventory;
  Room* currentRoom = Living_Room;
  
  //Playing loop
  while(play) {
    //Showing room info and if item there or not
    currentRoom->printinfo();
    //Finding what user wants to do
    cout << "Enter what you want to do: (GRAB, MOVE, or QUIT)" << endl;
    cin >> c_input;
    //User wants to grab
    if(strcmp(c_input, "GRAB") == 0) {
      char itemGrab[SIZE];
      cout << "Enter the name of the item you wish to grab: " << endl;
      cin >> itemGrab;
      //Finding item and adding to inventory
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
      //Item doesnt match
      else {
	cout << "There is no item with that name in this room, maybe you spell it wrong. " << endl;
      }
    }
    //User wants to move
    else if(strcmp(c_input, "MOVE") == 0) {
      char direction[SIZE];
      cout << "Enter what direction you want to move (North, East, South, West): " << endl;
      cin >> direction;
      //Making sure players direction is a valid move
      if (currentRoom->getExit(direction) != NULL) {
	currentRoom = currentRoom->getExit(direction);
	cout << "You moved this direction: " << direction << endl;
      }
      //Not valid
      else {
	cout << "This direction is not valid. Try again(check spelling)" << endl;
      }
    }
    //User wants to quit
    else if(strcmp(c_input, "QUIT") == 0) {
      play = false;
    }
    else if(strcmp(c_input, "DROP") == 0) {
      cout << "What item do you want to drop?" << endl;
      char* drop_item = new char[SIZE];
      char drop_item_input[SIZE];
      cin >> drop_item_input;
      strcpy(drop_item, drop_item_input);
      for(auto it = playerInventory.begin(); it != playerInventory.end(); ++it) {
        if(strcmp((*it)->getName(), drop_item) == 0) {
          Item *item = *it;
          playerInventory.erase(it);
          currentRoom->Items(*it);
          cout << "You dropped: " << drop_item << endl;
          break;
        }
      }
    }
  }
}
