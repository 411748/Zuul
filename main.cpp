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
  bool play = true;
  while(play) {
    cout << "Enter what you want to do: (GRAB, MOVE, or QUIT)" << endl;
    cin >> c_input;
    if(strcmp(c_input, "GRAB") == 0) {
      // Grab code
    }
    else if(strcmp(c_input, "MOVE") == 0) {
      // Move code
    }
    else if(strcmp(c_input, "QUIT") == 0) {
      play = false;
    }
  }
}
