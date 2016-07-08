#pragma once
#include "../LabelContainer/LabelContainer.h"
class CheckList:public LabelContainer
{
	vector<int> _selectedIndices;
	bool IsSelected(int index);
	void DeselectItem(int index);
public:
	CheckList(int width, vector<string> items);
	void SetSelectedIndex(int index);
	vector<int> GetSelectedIndices();
	virtual void MousePressed(int x, int y, bool isLeft);
	virtual void KeyDown(int keyCode, char character);
	void ToggleSelection(int index);
	~CheckList();
};

