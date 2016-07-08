#include "LabelContainer.h"


void LabelContainer::AddItem(string item, int width)
{
	Label* l = NULL;
	l = new Label(width);
	l->SetFocusFlag(true);
	while (item.size() < width)
		item += " ";
	l->SetText(item);
	Panel::AddWidget(*l, 0, _numberOfWidgets);
}

LabelContainer::LabelContainer(int width, vector<string> items, bool markable) :Panel(width, 1)
{
	SetHeight(items.size());
	SetFocusFlag(true);
	string str = "[ ] ";
	for (int i = 0; i < items.size(); ++i)
	{
		if (markable)
			items[i].insert(0, str);
		AddItem(items[i], width);
	}
	if (_numberOfWidgets > 0)
		_widgetInFocus = _widgetList[0];
}

void LabelContainer::FocusEvent()
{
	_widgetInFocus->FocusEvent();
}

void LabelContainer::MousePressed(int x, int y, bool isLeft)
{
	//Disables focus on current widget in focus
	_widgetInFocus->FocusEvent();
	_widgetInFocus = _widgetList[y];
	//Enables focus on the new widget in focus
	_widgetInFocus->FocusEvent();
}

void LabelContainer::KeyDown(int keyCode, char character)
{
	int index = 0;
	index = GetIndexOfWidget(_widgetInFocus);
	if (keyCode == VK_UP)
	{
		if ((index - 1) < 0)
			index = _numberOfWidgets - 1;
		else
			index -= 1;
		ChangeLocalWidgetInFocus(index);
	}
	else if (keyCode == VK_DOWN)
		ChangeLocalWidgetInFocus((index + 1) % _numberOfWidgets);
}

void LabelContainer::ChangeLocalWidgetInFocus(int index)
{
	_widgetInFocus->FocusEvent();
	_widgetInFocus = _widgetList[index];
	_widgetInFocus->FocusEvent();
}

void LabelContainer::GetAllControls(vector<Widget*>& controls)
{
	Panel::GetAllControls(controls);
	if (this == Widget::GetFocus())
	{
		int index = GetIndexOfWidget(_widgetInFocus) + 1 > _numberOfWidgets - 1 ? GetIndexOfWidget(_widgetInFocus) : GetIndexOfWidget(_widgetInFocus) + 1;
		Widget::SetFocus(*_widgetList[index]);
	}
}

LabelContainer::~LabelContainer()
{
	for (int i = 0; i < _numberOfWidgets; ++i)
		delete _widgetList[i];
}



