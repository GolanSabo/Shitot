#pragma once
#include "../Panel/Panel.h"
#include "../Button/Button.h"
#include "../Label/Label.h"
struct NumericBoxListener;
class NumericBox:public Panel
{
	int _max, _min,_currentValue;
	void InitNumericBox();
	NumericBoxListener* listener;

public:
	NumericBox(int width, int min, int max);
	bool SetValue(int x);
	int GetValue();
	void MousePressed(int x, int y, bool isLeft);
	void AddWidget(Widget& widget, int x, int y) = delete;
	~NumericBox();

};

