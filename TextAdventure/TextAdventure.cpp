#include <iostream>
#include "EntranceRoom.h"
#include "Map.h"

// interface
// map or game board
// characters and enemies
// randomness

int main()
{
	Map myMap(25, 25);
	std::cout << myMap.ToString();
}
