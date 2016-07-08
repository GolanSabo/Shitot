#pragma once

#include <vector>
#include "../Graphics/Graphics.h"
#include "../BorderDrawer/BorderDrawer.h"
using namespace std;

class Widget
{
	int _x, _y, _width, _height,_layer;
	bool _visibility, _focusable, _editable;
	Color _foregroundColor;
	Color _backgroundColor;
	BorderType _borderType;
	const BorderDrawer* _borderDrawer;
	string _content;
	int _cursorPosition;

public:
	bool GetFocusFlag();
	void SetFocusFlag(bool flag);

	int GetCursorPosition();
	void SetCursorPosition(int pos);

	Widget(int width, int height);

	bool GetEditable();
	void SetEditable(bool editable);

	bool GetVisibility();
	void SetVisibility(bool visibility);
	
	Color GetForeground();
	void SetForeground(Color color);
	
	Color GetBackground();
	void SetBackground(Color color);
	
	//BorderType GetBorder();
	//void SetBorder(BorderType border);

	int GetWidth();
	void SetWidth(int width);

	int GetHeight();
	void SetHeight(int height);

	int GetX();
	void SetX(int x);

	int GetY();
	void SetY(int y);

	string GetText();
	virtual void SetText(string text);

	void SetBorderDrawer(BorderDrawer& borderDrawer);
	virtual void Draw(Graphics g, int x, int y, int layer);
	virtual void FocusEvent();
	virtual void MousePressed(int x, int y, bool isLeft) = 0;
	virtual void KeyDown(int keyCode, char character) = 0;


	static Widget* GetFocus();
	static void SetFocus(Widget& wid);

	int GetLayer();
	virtual void SetLayer(int layer);


	virtual void GetAllControls(vector<Widget*>& controls);

	bool CheckPosition(int x, int y) const;
	~Widget();
};

class MouseListener
{
public:
	virtual void MousePressed(Widget &control, int x, int y, bool isLeft) = 0;
};
