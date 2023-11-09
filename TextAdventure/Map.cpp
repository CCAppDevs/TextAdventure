#include "Map.h"


int Map::GetRandomNumber(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distr(min, max);
	return distr(gen);
}

Map::Map(int sizeX, int sizeY)
{

	SharedEntranceRoom = make_shared<EntranceRoom>("The stairs lead you down into the dungeon...");
	SharedEmptyRoom = make_shared<EmptyRoom>("This room is dusty but otherwise empty.");
	SharedEncounterRoom = make_shared<EncounterRoom>("You walk into the room and are suddenly faced with a ", "Goblin");

	// generate the map
	Rooms.resize(sizeY);

	for (int i = 0; i < sizeY; i++) {
		Rooms.resize(sizeX);
		for (int j = 0; j < sizeX; j++) {
			// choose the room
			int roomChoice = GetRandomNumber(1, 10);

			if (i == 0 && j == 0) {
				Rooms[i].push_back(SharedEntranceRoom);
			} else if (roomChoice > 9) {
				Rooms[i].push_back(SharedEncounterRoom);
			/*}
			else if (roomChoice > 2) {
				Rooms[i].push_back(SharedEmptyRoom);*/
			} else {
				Rooms[i].push_back(SharedEmptyRoom);
			}
		}
	}
}

void Map::MoveX(int amount)
{
	// at the left side, cant go negative
	// at the right side, cant go positive

	// move right (+1)
	if (amount > 0 && PlayerPosition.x < Rooms[0].size() - 1) {
		PlayerPosition.x += amount;
	}
	else if (amount < 0 && PlayerPosition.x > 0) { // move left (-1)
		PlayerPosition.x += amount;
	}
}

void Map::MoveY(int amount)
{
	// move down (+1)
	if (amount > 0 && PlayerPosition.y < Rooms.size() - 1) {
		PlayerPosition.y += amount;
	}
	else if (amount < 0 && PlayerPosition.y > 0) { // move up (-1)
		PlayerPosition.y += amount;
	}
}

std::string Map::GetCurrentRoomDescription()
{
	return Rooms[PlayerPosition.y][PlayerPosition.x]->GetDescription();
}

std::string Map::ToString()
{
	// we need to loop through the array and capture the toString of each room individual
	std::string output = "";

	for (int i = 0; i < Rooms.size(); i++) {
		for (int j = 0; j < Rooms[i].size(); j++) {
			if (PlayerPosition.x == j && PlayerPosition.y == i) {
				output += "[P]";
			}
			else {
				output += Rooms[i][j]->ToString();
			}
		}
		output += "\n";
	}

	output += "\n" + GetCurrentRoomDescription();

	return output;
}
