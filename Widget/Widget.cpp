#include "Widget.h"

static Widget* Focused;

void Widget::SetFocusFlag(bool flag)
{
	_focusable = flag;
}

bool Widget::GetFocusFlag()
{
	return _focusable;
}

int Widget::GetCursorPosition()
{
	return _cursorPosition;
}
void Widget::SetCursorPosition(int pos)
{
	_cursorPosition = pos;
}

Widget::Widget(int width, int height) :_width(width), _height(height), _content(""),
_foregroundColor(Color::White), _backgroundColor(Color::Black),
_editable(false), _focusable(false), _cursorPosition(0)
{
	_borderDrawer = &(BorderFactory::instance().getNull());
}

bool Widget::GetEditable()
{
	return _editable;
}
void Widget::SetEditable(bool editable)
{
	_editable = editable;
}

bool Widget::GetVisibility()
{
	return _visibility;
}

void Widget::SetVisibility(bool visibility)
{
	_visibility = visibility;
}

Color Widget::GetForeground()
{
	return _foregroundColor;
}
void Widget::SetForeground(Color color)
{
	_foregroundColor = color;
}

Color Widget::GetBackground()
{
	return _backgroundColor;
}

void Widget::SetBackground(Color color)
{
	_backgroundColor = color;
}

int Widget::GetWidth()
{
	return _width;
}
void Widget::SetWidth(int width)
{
	_width = width;
}

int Widget::GetHeight()
{
	return _height;
}
void Widget::SetHeight(int height)
{
	_height = height;
}

int Widget::GetX()
{
	return _x;
}
void Widget::SetX(int x)
{
	_x = x;
}

int Widget::GetY()
{
	return _y;
}
void Widget::SetY(int y)
{
	_y = y;
}

string Widget::GetText()
{
	return _content;
}
void Widget::SetText(string text)
{
	_content = text;
}

void Widget::SetBorderDrawer(BorderDrawer& borderDrawer)
{
	_borderDrawer = &borderDrawer;
}

void Widget::Draw(Graphics g, int x, int y, int layer)
{
	if (layer != _layer)
		return;
	g.setBackground(_backgroundColor);
	g.setForeground(_foregroundColor);
	_borderDrawer->Draw(g, x + _x - 1, y + _y - 1, _width, _height);
	g.write(x + _x, y + _y, _content);
}

void Widget::FocusEvent()
{
	if (_focusable)
	{
		Color tmp = _backgroundColor;
		_backgroundColor = _foregroundColor;
		_foregroundColor = tmp;
	}
}

Widget* Widget::GetFocus()
{
	return Focused;
}

void Widget::SetFocus(Widget& wid)
{
	if (Focused != nullptr)
		Focused->FocusEvent();
	Focused = &wid;
	Focused->FocusEvent();
}

int Widget::GetLayer()
{
	return _layer;
}
void Widget::SetLayer(int layer)
{
	_layer = layer;
}

void Widget::GetAllControls(vector<Widget*>& controls)
{
	controls.push_back(this);
}

bool Widget::CheckPosition(int x, int y) const
{	

	if (x < _x || x > _x + _width || y < _y || y > _y + _height)
		return false;

	return true;
}

Widget::~Widget()
{
}

