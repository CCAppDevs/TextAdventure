#include <iostream>
#include "EntranceRoom.h"

// interface
// map or game board
// characters and enemies
// randomness

int main()
{
	EntranceRoom room = EntranceRoom("This is the entrance.");

	std::cout << room.ToString();
	std::cout << "You encountered a new room!\n";
	std::cout << room.GetDescription() << "\n";
}
