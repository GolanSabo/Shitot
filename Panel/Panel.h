#pragma once
#include "../Widget/Widget.h"
class Panel:public Widget
{
protected:
	vector<Widget*> _widgetList;
	int _numberOfWidgets;
	int GetIndexOfWidget(Widget* wid);
public:
	Panel(int width = 10, int height = 10);
	void AddWidget(Widget& widget, int x, int y);
	virtual void MousePressed(int x, int y, bool isLeft);
	virtual void KeyDown(int keyCode, char character);
	virtual void Draw(Graphics g, int x, int y, int layer);
	virtual void FocusEvent();
	void SetLayer(int layer);
	virtual void GetAllControls(vector<Widget*>& controls);
	virtual void Hide();
	virtual void Show();
	int GetCursorPosition() = delete;
	void SetCursorPosition(int pos) = delete;
	~Panel();
};

