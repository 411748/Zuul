#include <iostream>
#include <cstring>
#include "item.h"
 
using namespace std;

Item::Item(const char* name) : name(name) {}

const char* Item::getName() const {
    return name;
}
