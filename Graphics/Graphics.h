#pragma once

#include <string>
#include <Windows.h>
using namespace std;
enum class BorderType { Single, Double, None };
enum class Color { Red, Blue, Green, Purple, Cyan, Orange, White, Black };
bool isInside(int x, int y, int left, int top, int width, int height);
class Graphics
{
	HANDLE _console;
	Color _background;
	Color	_foreground;

	void updateConsoleAttributes();
public:
	Graphics(DWORD stdHandle = STD_OUTPUT_HANDLE);
	void clearScreen();
	void moveTo(int x, int y);
	void setBackground(Color color);
	void setForeground(Color color);
	void write(string s);
	void write(int x, int y, string s);

	void setCursorVisibility(bool isVisible);
};

