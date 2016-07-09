#include "TextBox.h"

TextBox::TextBox(int width) :Widget(width, 1)
{
	SetEditable(true);
	SetFocusFlag(true);
}

bool TextBox::IsCharacter(int keyCode)
{
	if (keyCode >= 20 && keyCode <= 126)
		return true;
	return false;
}

void TextBox::SetText(string text)
{
	if (!_cursorSet)
	{
		SetCursorPosition(min(text.size(), GetWidth()));
		_cursorSet = true;
	}
	Widget::SetText(text);
}

void TextBox::MousePressed(int x, int y, bool isLeft)
{
	SetCursorPosition(min(x - GetX(), GetText().size()));
}

void TextBox::Draw(Graphics g, int x, int y, int layer)
{
	Widget::Draw(g, x, y, layer);
	g.moveTo(x + GetCursorPosition(), y);
}

void TextBox::KeyDown(int keyCode, char character)
{
	int position = GetCursorPosition();
	switch (keyCode)
	{
	case VK_LEFT:
		SetCursorPosition(max(position - 1, 0));
		break;
	case VK_RIGHT:
		SetCursorPosition(min(position + 1, GetText().size()));
		break;
	case VK_DELETE:
		if (position <= GetText().size())
			SetText(GetText().erase(position, 1));
		break;
	case VK_BACK:
		if (position > 0)
		{
			SetText(GetText().erase(position - 1, 1));
			SetCursorPosition(position - 1);
		}
		break;
	default:
		if (position >= 0 && position <= GetWidth() && IsCharacter(character) && GetText().size() < GetWidth())
		{
			SetText(GetText().insert(position, 1, character));
			SetCursorPosition(position + 1);
		}
	}
}


TextBox::~TextBox()
{
}
