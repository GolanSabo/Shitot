#pragma once
#include "../Widget/Widget.h"

#include <Windows.h>
class EventEngine
{
public:
	EventEngine(DWORD input = STD_INPUT_HANDLE, DWORD output = STD_OUTPUT_HANDLE);
	void run(Widget &c);
	virtual ~EventEngine();
private:
	void moveFocus(Widget &main, Widget *focused);
    Graphics _graphics;
	HANDLE _console;
	DWORD _consoleMode;
};