#include "ComboBox.h"


ComboBox::ComboBox(int width, vector<string> items) :LabelContainer(width, items, false), _openFlag(false), l1(3)
{
	l1.SetText(" v ");
	Panel::AddWidget(l1, width - 3, 0);
}

void ComboBox::SetSelectedIndex(int index)
{
	SwapItems(0, index);
}

void ComboBox::SwapItems(int index1, int index2)
{
	index1 = index1 >= _numberOfWidgets - 1 ? _numberOfWidgets - 2 : index1;
	index2 = index2 >= _numberOfWidgets - 1 ? _numberOfWidgets - 2 : index2;
	string str = _widgetList[index1]->GetText();
	_widgetList[index1]->SetText(_widgetList[index2]->GetText());
	_widgetList[index2]->SetText(str);
}

int ComboBox::GetSelectedIndex()
{
	return 0;
}

void ComboBox::Draw(Graphics g, int x, int y, int layer)
{
	if (_openFlag)
	{
		SetHeight(_numberOfWidgets - 1);
		LabelContainer::Draw(g, x, y, layer);
		l1.SetText(" ^ ");
	}
	else
	{
		SetHeight(1);
		if (layer == GetLayer())
			Widget::Draw(g, x, y, layer);
		_widgetList[0]->Draw(g, GetX() + x, GetY() + y, layer);
		l1.SetText(" v ");
	}
	l1.Draw(g, GetX() + x, GetY() + y, layer);
}

void ComboBox::MousePressed(int x, int y, bool isLeft)
{
	y -= GetY();
	if (y >= 0 && _openFlag)
	{
		SwapItems(0, y);
		_openFlag = false;
		if (y != 0)
			LabelContainer::ChangeLocalWidgetInFocus(0);
	}
	else
	{
		_openFlag = true;
		SetHeight(_numberOfWidgets - 1);
	}
}

void ComboBox::FocusEvent()
{
	_widgetList[0]->FocusEvent();
}

void ComboBox::KeyDown(int keyCode, char character)
{
	if (_openFlag)
	{
		if (keyCode == VK_RETURN)
		{
			int y = GetIndexOfWidget(_widgetInFocus);
			SwapItems(0, y);
			_openFlag = false;
			if (y != 0)
				LabelContainer::ChangeLocalWidgetInFocus(0);
			return;
		}
		LabelContainer::KeyDown(keyCode, character);
	}
}

void ComboBox::GetAllControls(vector<Widget*>& controls)
{
	if (_openFlag)
	{
		if (this == Widget::GetFocus())
		{
			if (GetIndexOfWidget(_widgetInFocus) == _numberOfWidgets - 2)
			{
				_openFlag = false;
				Widget::GetAllControls(controls);
				ChangeLocalWidgetInFocus(0);
				return;
			}
			int index = ((GetIndexOfWidget(_widgetInFocus) + 1) % (_numberOfWidgets - 1));
			ChangeLocalWidgetInFocus(index);
		}
		else
		{
			_widgetInFocus = _widgetList[0];
			Widget::GetAllControls(controls);
		}
	}
	else 
	{
		Widget::GetAllControls(controls);
	}
}

ComboBox::~ComboBox()
{
}
