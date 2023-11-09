#pragma once
#include <vector>
#include <string>
#include <memory>
#include <random>
#include "AbstractRoom.h"
#include "EmptyRoom.h"
#include "EntranceRoom.h"
#include "EncounterRoom.h"


// rooms 2d array or vector
// coordinate

/*

pointer* - everyday normal pointer that we must manage

smart pointers
auto_ptr - automatically chooses the type of pointer to use - deprecated, do not use
unique_ptr - only one copy of the ptr in memory
shared_ptr - this can be used to share multiple instances of a single object
weak_ptr - this is a shared ptr that stops circular references
*/

using namespace std;

struct Coord {
	int x;
	int y;

	Coord() {
		x = 0;
		y = 0;
	}
};

class Map
{
private:
	Coord PlayerPosition;
	vector<vector<shared_ptr<AbstractRoom>>> Rooms;

	shared_ptr<EntranceRoom> SharedEntranceRoom;
	shared_ptr<EmptyRoom> SharedEmptyRoom;
	shared_ptr<EncounterRoom> SharedEncounterRoom;

	int GetRandomNumber(int min, int max);

public:
	Map(int sizeX, int sizeY);

	// player movement
	void MoveX(int amount);
	void MoveY(int amount);

	std::string GetCurrentRoomDescription();

	std::string ToString();
};

