#pragma once
#include "../Widget/Widget.h"
class Label:public Widget
{
public:
	Label(int width);
	virtual void MousePressed(int x, int y, bool isLeft);
	virtual void KeyDown(int keyCode, char character);
	int GetCursorPosition() = delete;
	void SetCursorPosition(int pos) = delete;
	~Label();
};

