#pragma once
#include "../Label/Label.h"
class Button :public Label
{
	vector<MouseListener*> _listener;
public:
	Button(int width);
	void AddListener(MouseListener &listener);
	virtual void MousePressed(int x, int y, bool isLeft);
	~Button();
};

