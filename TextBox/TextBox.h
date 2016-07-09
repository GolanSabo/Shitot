#pragma once
#include "../Widget/Widget.h"
#include <map>

class TextBox :public Widget
{
	bool _cursorSet;

public:
	TextBox(int width);

	void Draw(Graphics g, int x, int y, int layer);
	bool IsCharacter(int keyCode);
	void SetText(string text);
	void MousePressed(int x, int y, bool isLeft);
	void KeyDown(int keyCode, char character);

	~TextBox();
};

