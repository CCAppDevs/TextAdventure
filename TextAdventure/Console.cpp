#include "Console.h"

Console::Console(Map& map, int outputLineCount)
{
	myMap = &map;
	OutputLineCount = outputLineCount;
	ShowConsoleCursor(false);
}

void Console::Out(string text)
{
	vector<string> lines = WrapLines(text);

	for (string line : lines) {
		OutputBuffer.push(line);
	}
}

void Console::Drain()
{
	for (int i = 0; i < OutputLineCount; i++) {
		if (OutputBuffer.size() == 0) {
			return;
		}
		OutputBuffer.pop();
	}
}

void Console::ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

string Console::MakeOutputString(string text)
{
	string output = "";
	int lineWidth = myMap->GetSizeX() * 3;
	
	vector<string> lines = WrapLines(text);

	for (int i = 0; i < 5; i++) {
		if (i < lines.size()) {
			string line(lineWidth, ' ');
			line.replace(0, lines[i].length(), lines[i]);
			output += line + "\n";
		}
		else {
			output += string(lineWidth, ' ') + "\n";
		}
	}

	return output;
}

string Console::GetBorder()
{
	string s(myMap->GetSizeX()*3, '#');
	return s;
}

vector<string> Console::WrapLines(string text)
{
	size_t curpos = 0;
	size_t nextpos = 0;
	size_t width = myMap->GetSizeX() * 3;

	vector<string> lines;
	string substr = text.substr(curpos, width + 1);

	while (substr.length() == width + 1 && (nextpos = substr.rfind(' ')) != text.npos) {
		lines.push_back(text.substr(curpos, nextpos));
		curpos += nextpos + 1;
		substr = text.substr(curpos, width + 1);
	}

	if (curpos != text.length())
		lines.push_back(text.substr(curpos, text.npos));

	return lines;
}

string Console::GetOutput()
{
	string output = "";
	for (int i = 0; i < OutputLineCount; i++) {
		if (i < OutputBuffer.size()) {
			output += OutputBuffer.top() + "\n";
			OutputBuffer.pop();
		}
		else {
			output += string(myMap->GetSizeX() * 3, ' ') + "\n";
		}
	}

	return output;
}

void Console::Draw()
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
	cout << myMap->ToString() << "\n";
	cout << GetBorder() << "\n";
	cout << GetOutput();

	myMap->GetCurrentRoom()->Execute();
	cout << GetBorder() << "\n";
}
