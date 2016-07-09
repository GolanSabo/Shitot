#pragma once
#include "../Graphics/Graphics.h"
#include <vector>
class GraphicsMock:public Graphics
{
	vector<char> _screen;
	int _x, _y;
public:
	GraphicsMock() :Graphics(STD_OUTPUT_HANDLE), _screen(25 * 80, '\0') {}
	void moveTo(int x, int y) { _x = x; _y = y; }
	void write(string str)
	{
		for (int i = 0; i < str.size(); ++i)
			_screen[_y * 80 + _x + i] = str[i];
	}
	void write(int x, int y, string str) { moveTo(x, y); write(str); }
	string GetStringAt(int x, int y, int size)
	{
		string str;
		for (; size; ++x, --size)
			str += _screen[y * 80 + x];
		return str;
	}
	void ClearAt(int x, int y, int size)
	{
		string str;
		for (; size; ++x, --size)
			_screen[y * 80 + x] = '\0';
	}
	bool IsClear()
	{
		for (int i = 0; i < _screen.size(); ++i)
			if (_screen[i])
				return false;
		return true;
	}
};

