#include "Map.h"

Map::Map(int x, int y)
{
    Rooms.resize(y);
    for (int i = 0; i < y; i++) {
        Rooms.resize(x);
        for (int j = 0; j < x; j++) {
            if (i == 0 && j == 0) {
                Rooms[i].push_back(make_shared<EntranceRoom>("toast"));
            }
            else {
                Rooms[i].push_back(make_shared<EmptyRoom>("toast"));
            }
        }
    }
}

std::string Map::ToString()
{
    std::string output = "";

    for (int i = 0; i < Rooms.size(); i++) {
        for (int j = 0; j < Rooms[i].size(); j++) {
            output += Rooms[i][j]->ToString();
        }
        output += "\n";
    }

    return output;
}
