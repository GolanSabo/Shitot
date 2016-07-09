#include "MassageBox.h"


struct HideListener : public MouseListener
{
	HideListener(Widget &w) : _w(w) { }
	void MousePressed(Widget &b, int x, int y, bool isLeft)
	{
		_w.SetText(b.GetText());
		_w.Hide();
	}
private:
	Widget &_w;
};

void MassageBox::initMassageBox()
{
	int size = GetWidth();
	Label* l = new Label(size);
	listener = new HideListener(*this);
	Button* b = new Button(6);
	b->SetText("  OK ");
	b->AddListener(*listener);
	b->SetBorderDrawer(BorderFactory::instance().getSingle());
	Button* b1 = new Button(6);
	b1->SetText("Cancel");
	b1->AddListener(*listener);
	b1->SetBorderDrawer(BorderFactory::instance().getSingle());
	Panel::AddWidget(*l, 0, 0);
	Panel::AddWidget(*b, GetWidth() - 8, GetHeight() - 2);
	Panel::AddWidget(*b1, 2, GetHeight() - 2);
}

MassageBox::MassageBox(int width, int height) :Panel(width, height)
{
	if (GetHeight() < 8)
		SetHeight(8);
	if (GetWidth() < 20)
		SetWidth(20);
	initMassageBox();
}

void MassageBox::SetVisibility(bool visibility)
{}

void MassageBox::SetText(string str)
{
	string tmp = "";
	if(GetWidth() - str.size())
		for (int i = 0; i < GetWidth() - str.size(); ++i)
		{
			if (i % 2 == 0)
				str.insert(0, " ");
			else
				str += ' ';
		}
	_widgetList[0]->SetText(str);
}

string MassageBox::GetClickResult()
{
	return Widget::GetText();
}
MassageBox::~MassageBox()
{
	for (int i = 0; i < _numberOfWidgets; ++i)
		delete _widgetList[i];
	delete listener;
}
