#pragma once
#include <vector>
#include "AbstractRoom.h"
#include "EntranceRoom.h"
#include "EmptyRoom.h"
#include <memory>

using namespace std;

class Map
{
	vector<vector<shared_ptr<AbstractRoom>>> Rooms;

public:
	Map(int x, int y);

	string ToString();
};

