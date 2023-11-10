#pragma once
#include <conio.h>
#include <Windows.h>
#include <iostream>
#include <stack>
#include "Map.h"

using namespace std;

class Console
{
private:
	void ShowConsoleCursor(bool showFlag);
	Map* myMap;
	stack<string> OutputBuffer;
	int OutputLineCount;

	string MakeOutputString(string text);
	string GetBorder();
	vector<string> WrapLines(string text);
	string GetOutput();

public:
	Console(Map& map, int outputLineCount);

	void Out(string text);
	void Drain();
	void Draw();

	bool isWaitingForInput = true;
};


