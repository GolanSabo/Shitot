#pragma once
#include "../Widget/Widget.h"
#include <map>
//#include <functional>
class TextBox :public Widget
{
	bool _cursorSet;
	//map<int, function<void(char)>> _handlers;

	//void RegisterHandler(vector<int> codes, function<void(char)> func);
public:
	TextBox(int width);

	void Draw(Graphics g, int x, int y, int layer);
	bool IsCharacter(int keyCode);
	void SetText(string text);
	void MousePressed(int x, int y, bool isLeft);
	void KeyDown(int keyCode, char character);

	~TextBox();
};

