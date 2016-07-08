#pragma once
#include "../Panel/Panel.h"
#include "../Label/Label.h"
#include "../Button/Button.h"
#include <vector>
class LabelContainer: public Panel
{
protected:
	Widget* _widgetInFocus;
	virtual void AddItem(string item, int width);
public:
	LabelContainer(int width, vector<string> items, bool markable = true);
	virtual void SetSelectedIndex(int index) = 0;
	virtual void FocusEvent();
	virtual void MousePressed(int x, int y, bool isLeft);
	virtual void KeyDown(int keyCode, char character);
	void ChangeLocalWidgetInFocus(int index);
	void LabelContainer::GetAllControls(vector<Widget*>& controls);
	void AddWidget(Widget& widget, int x, int y) = delete;
	~LabelContainer();
};

