#include "EncounterRoom.h"

EncounterRoom::EncounterRoom(std::string desc, std::string monsterType) : AbstractRoom(desc)
{
    MonsterType = monsterType;
}

bool EncounterRoom::Execute()
{
	bool running = true;
    std::cout << "You have triggered an encounter\n";
	while (running) {
		int choice = -1;

		std::cin >> choice;

		switch (choice) {
		case 0:
			running = false;
			break;
		default:
			break;
		}
	}

	return false;
}

std::string EncounterRoom::ToString()
{
    return "[M]";
}
