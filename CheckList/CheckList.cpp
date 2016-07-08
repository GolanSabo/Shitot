#include "CheckList.h"

bool CheckList::IsSelected(int index)
{
	if (_widgetList[index]->GetText()[1] == 'x')
		return true;
	return false;
}

void CheckList::DeselectItem(int index)
{
	for (int i = 0; i < _selectedIndices.size(); ++i)
		if (_selectedIndices[i] == index)
		{
			_selectedIndices.erase(_selectedIndices.begin() + i);
			string str = _widgetList[index]->GetText();
			str.replace(1, 1, " ");
			_widgetList[index]->SetText(str);
		}
}

CheckList::CheckList(int width, vector<string> items) :LabelContainer(width, items), _selectedIndices()
{
}

void CheckList::SetSelectedIndex(int index)
{
	_selectedIndices.push_back(index);
	string str = _widgetList[index]->GetText();
	str.replace(1, 1, "x");
	_widgetList[index]->SetText(str);
}

void CheckList::MousePressed(int x, int y, bool isLeft)
{
	y -= GetY();
	ToggleSelection(y);

	LabelContainer::MousePressed(x, y, isLeft);
}

void CheckList::KeyDown(int keyCode, char character)
{
	if (keyCode == VK_RETURN)
		ToggleSelection(GetIndexOfWidget(_widgetInFocus));
	else
		LabelContainer::KeyDown(keyCode, character);
}

vector<int> CheckList::GetSelectedIndices()
{
	return _selectedIndices;
}

void CheckList::ToggleSelection(int index)
{
	if (IsSelected(index))
		DeselectItem(index);
	else
		SetSelectedIndex(index);
}

CheckList::~CheckList()
{
}
