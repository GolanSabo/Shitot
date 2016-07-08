#include "Button.h"



Button::Button(int width) :Label(width), _listener()
{
}

void Button::AddListener(MouseListener &listener)
{
	_listener.push_back(&listener);
}

void Button::MousePressed(int x, int y, bool isLeft)
{
	if(_listener.empty())
		return;
	for (int i = 0; i < _listener.size(); ++i)
	{
		_listener[i]->MousePressed(*this, x, y, isLeft);
	}
}

Button::~Button()
{
}
