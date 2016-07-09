#pragma once
#include "../EventEngine/EventEngine.h"
#include "../Button/Button.h"
#include "../Label/Label.h"
#include "../Panel/Panel.h"
#include "../TextBox/TextBox.h"
#include "../ComboBox/ComboBox.h"
#include "../RadioList/RadioList.h"
#include "../CheckList/CheckList.h"
#include "../NumericBox/NumericBox.h"
#include "../MassageBox/MassageBox.h"
struct MyListener: public MouseListener
{
	MyListener(Widget &c) : _c(c) { }
	void MousePressed(Widget &b, int x, int y, bool isLeft)
	{
		_c.SetForeground(Color::Red);
	}
private:
	Widget &_c;
};

class StarsBorderDrawer : public BorderDrawer
{
public:
	inline void Draw(Graphics &g, int left, int top, int width, int height)const
	{
		char frame[]{ '*', '*', '*', '*', '*', '*' };
		DrawFrame(g, left, top, width, height, frame);
	}
};

int main(int argc, char **argv)
{
	Label lName(20);
	lName.SetText("Name: ");
	lName.SetBackground(Color::Green);
	lName.SetForeground(Color::Red);
	Label lAddress(20);
	lAddress.SetText("Address:");
	Label lCountry(20);
	lCountry.SetText("Counrty:");
	Label lSex(20);
	lSex.SetText("Sex:");
	Label lInterests(20);
	lInterests.SetText("Interests:");
	Label lAge(20);
	lAge.SetText("Age:");
	TextBox tName(20);
	tName.SetText("Sherlock Holmes");
	tName.SetBorderDrawer(BorderFactory::instance().getSingle());
	TextBox tAddress(25);
	tAddress.SetText("221B Baker Street, London");
	tAddress.SetBorderDrawer(BorderFactory::instance().getSingle());
	ComboBox cCountry(20, { "Israel", "Great Britain", "United States" });
	cCountry.SetSelectedIndex(1);
	cCountry.SetLayer(1);
	cCountry.SetBorderDrawer(BorderFactory::instance().getSingle());
	RadioList rSex(15, { "Male", "Female" });
	rSex.SetBorderDrawer(BorderFactory::instance().getSingle());
	CheckList clInterests(15, { "Sports", "Books", "Movies" });
	clInterests.SetSelectedIndex(1);
	clInterests.SetBorderDrawer(BorderFactory::instance().getSingle());
	NumericBox nAge(15, 18, 120);
	nAge.SetValue(23);
	nAge.SetBorderDrawer(BorderFactory::instance().getSingle());
	MyListener listener(lAddress);
	Button bSubmit(10);
	bSubmit.SetText("Submit");
	bSubmit.AddListener(listener);
	bSubmit.SetBorderDrawer(BorderFactory::instance().getDouble());
	MassageBox m;
	m.SetText("MassageBox!");
	StarsBorderDrawer* b = new StarsBorderDrawer();
	m.SetBorderDrawer(*b);
	m.SetLayer(4);
	Panel main;
	main.AddWidget(lName, 1, 2);
	main.AddWidget(lAddress, 1, 5);
	main.AddWidget(lCountry, 1, 8);
	main.AddWidget(lSex, 1, 11);
	main.AddWidget(lInterests, 1, 15);
	main.AddWidget(lAge, 1, 20);
	main.AddWidget(tName, 25, 2);
	main.AddWidget(tAddress, 25, 5);
	main.AddWidget(cCountry, 25, 8);
	main.AddWidget(rSex, 25, 11);
	main.AddWidget(clInterests, 25, 15);
	main.AddWidget(nAge, 25, 20);
	main.AddWidget(bSubmit, 1, 22);
	main.AddWidget(m, 45, 15);
	Widget::SetFocus(tAddress);
	EventEngine engine;
	engine.run(main);
	return 0;
}

