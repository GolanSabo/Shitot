#include "EventEngine.h"
#define NUMBER_OF_LAYERS 5
EventEngine::EventEngine(DWORD input, DWORD output)
	: _console(GetStdHandle(input)), _graphics(output)
{
	GetConsoleMode(_console, &_consoleMode);
	SetConsoleMode(_console, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
}

void EventEngine::run(Widget &c)
{
	bool cursorVisibility = false;
	for (bool redraw = true;;)
	{
		auto f = Widget::GetFocus();
		if (redraw)
		{
			_graphics.clearScreen();
			for (int p = 0; p < NUMBER_OF_LAYERS; ++p)
				c.Draw(_graphics, 0, 0, p);
			if (f != nullptr)
			{
				cursorVisibility = Widget::GetFocus()->GetEditable();
				_graphics.moveTo(f->GetX() + f->GetCursorPosition(), f->GetY());
				_graphics.setCursorVisibility(cursorVisibility);
			}
			redraw = false;
		}

		INPUT_RECORD record;
		DWORD count;
		ReadConsoleInput(_console, &record, 1, &count);
		switch (record.EventType)
		{
		case KEY_EVENT:
		{

			if (f != nullptr && record.Event.KeyEvent.bKeyDown)
			{
				auto code = record.Event.KeyEvent.wVirtualKeyCode;
				auto chr = record.Event.KeyEvent.uChar.AsciiChar;
				if (code == VK_TAB)
					moveFocus(c, f);
				else
					f->KeyDown(code, chr);
				//_graphics.moveTo(f->GetX() + f->GetText().size(), f->GetY());

				redraw = true;
			}
			break;
		}
		case MOUSE_EVENT:
		{
			auto button = record.Event.MouseEvent.dwButtonState;
			auto coord = record.Event.MouseEvent.dwMousePosition;
			auto x = coord.X - c.GetX();
			auto y = coord.Y - c.GetY();
			if (button == FROM_LEFT_1ST_BUTTON_PRESSED || button == RIGHTMOST_BUTTON_PRESSED)
			{
				c.MousePressed(x, y, button == FROM_LEFT_1ST_BUTTON_PRESSED);
				//_graphics.moveTo(x, y);
				redraw = true;
			}
			break;
		}
		default:
			break;
		}
	}
}

EventEngine::~EventEngine()
{
	SetConsoleMode(_console, _consoleMode);
}

void EventEngine::moveFocus(Widget &main, Widget *focused)
{
	vector<Widget*> controls(0);
	main.GetAllControls(controls);
	for (int i = 0; i < controls.size(); ++i)
		if (focused == controls[i])
		{
			while (!controls[(++i) % controls.size()]->GetFocusFlag());
			Widget::SetFocus(*controls[(i) % controls.size()]);
		}


	//auto it = find(controls.begin(), controls.end(), focused);
	//do
	//	if (++it >= controls.end())
	//		it = controls.begin();
	//while (!(*it)->GetFocusFlag());
	//Widget::SetFocus(**it);
}