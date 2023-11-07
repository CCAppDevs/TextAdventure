#include <iostream>
#include "Map.h"

// interface
// map or game board
// characters and enemies
// randomness

using namespace std;

int main()
{
	Map myMap = Map(25, 25);

	cout << myMap.ToString();
}
