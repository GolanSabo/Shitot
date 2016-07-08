#pragma once
#include "../LabelContainer/LabelContainer.h"
class RadioList :public LabelContainer
{
	int _selectedIndex;

protected:
	void MarkSelectedItem(int item);
public:
	RadioList(int width, vector<string> items);
	void SetSelectedIndex(int index);
	int GetSelectedIndex();
	virtual void MousePressed(int x, int y, bool isLeft);
	//void AddWidget(Widget& widget, int x, int y) = delete;
	virtual void KeyDown(int keyCode, char character);
	~RadioList();
};

