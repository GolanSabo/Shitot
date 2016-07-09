#include "NumericBox.h"

struct NumericBoxListener : public MouseListener
{
	NumericBoxListener(NumericBox &c) : _c(c) { }
	void MousePressed(Widget &b, int x, int y, bool isLeft)
	{
		int number = _c.GetValue();
		if (b.GetText().find("+") != string::npos)
			++number;
		else
			--number;

		_c.SetValue(number);
	}
private:
	NumericBox &_c;
};

void NumericBox::InitNumericBox()
{
	int size = GetWidth()/ 3;
	Label* l = new Label(GetWidth() - 2 * size);
	listener = new NumericBoxListener(*this);
	Button* b = new Button(size);
	b->SetText(" + ");
	b->AddListener(*listener);
	Button* b1 = new  Button(size);
	b1->SetText(" - ");
	b1->AddListener(*listener);
	Panel::AddWidget(*b1, 0, 0);
	Panel::AddWidget(*l, size, 0);
	Panel::AddWidget(*b, size + l->GetWidth() , 0);
}

NumericBox::NumericBox(int width, int min, int max):Panel(width, 1),_max(max),_min(min),_currentValue((max + min) / 2)
{
	InitNumericBox();
}

bool NumericBox::SetValue(int x)
{
	if (x <= _max && x >= _min)
	{
		_currentValue = x;
		_widgetList[1]->SetText(to_string(x));
		return true;
	}
	return false;
}

int NumericBox::GetValue()
{
	return _currentValue;
}

void NumericBox::MousePressed(int x, int y, bool isLeft)
{
	for (int i = 0; i < _numberOfWidgets; ++i)
	{
		if (_widgetList[i]->CheckPosition(x - GetX(), y - GetY()))
		{
			_widgetList[i]->MousePressed(x - GetX(), y - GetY(), isLeft);
			return;
		}
	}
}

NumericBox::~NumericBox()
{
	for (int i = 0; i < _numberOfWidgets; ++i)
		delete _widgetList[i];
	delete listener;
}

