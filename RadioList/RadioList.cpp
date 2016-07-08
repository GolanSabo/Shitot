#include "RadioList.h"

void RadioList::MarkSelectedItem(int item)
{
	for (int i = 0; i < _numberOfWidgets; ++i)
	{
		string str = _widgetList[i]->GetText();
		if (item == i)
			str.replace(1, 1, "x");
		else
			str.replace(1, 1, " ");
		_widgetList[i]->SetText(str);
	}
}

RadioList::RadioList(int width, vector<string> items) :LabelContainer(width, items)
{
}

void RadioList::SetSelectedIndex(int index)
{
	_selectedIndex = index;
}

int RadioList::GetSelectedIndex()
{
	return _selectedIndex;
}

void RadioList::MousePressed(int x, int y, bool isLeft)
{
	y -= GetY();
	MarkSelectedItem(y);
	LabelContainer::MousePressed(x, y, isLeft);
}
void RadioList::KeyDown(int keyCode, char character)
{
	if (keyCode == VK_RETURN)
		MarkSelectedItem(GetIndexOfWidget(_widgetInFocus));
	else
		LabelContainer::KeyDown(keyCode, character);
}
RadioList::~RadioList()
{
}
