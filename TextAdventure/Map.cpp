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

AbstractRoom& Map::GetRoom(int x, int y)
{
	// TODO: insert return statement here
	return *Rooms[y][x];
}