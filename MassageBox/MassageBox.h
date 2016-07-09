#pragma once
#include "../Panel/Panel.h"
#include "../Button/Button.h"
class MassageBox : public Panel
{
	MouseListener* listener;
	void initMassageBox();
public:
	MassageBox(int width = 20, int height = 8);
	virtual void SetVisibility(bool visibility);
	void SetText(string str);
	string GetClickResult();
	void AddWidget(Widget& widget, int x, int y) = delete;
	~MassageBox();
};

