#pragma once
#include "../Graphics/Graphics.h"
#include <iostream>

void DrawFrame(Graphics &g, int left, int top, int width, int height, char* frame);
void DrawLine(int width, char left, char right, char mid);
class SingleBorderDrawer;
class DoubleBorderDrawer;
class DoubleBorderDrawer;
class NullBorderDrawer;
class BorderFactory;
struct BorderDrawer {
	virtual void Draw(Graphics &g, int left, int top, int width, int height) const = 0;
};

class SingleBorderDrawer : public BorderDrawer 
{
public:
	inline void Draw(Graphics &g, int left, int top, int width, int height)const
	{
		char frame[]{ '\xDA', '\xBF', '\xC0', '\xD9', '\xB3', '\xC4' };
		DrawFrame(g, left, top, width, height, frame);
	}
};

class DoubleBorderDrawer : public BorderDrawer
{
public:
	inline void Draw(Graphics &g, int left, int top, int width, int height)const
	{
		char frame[]{ '\xC9', '\xBB', '\xC8', '\xBC', '\xBA', '\xCD' };
		DrawFrame(g, left, top, width, height, frame);
	}
};

class NullBorderDrawer : public BorderDrawer
{
public:
	inline void Draw(Graphics &g, int left, int top, int width, int height)const
	{}
};


class BorderFactory 
{
	NullBorderDrawer _null; 
	SingleBorderDrawer _single; 
	DoubleBorderDrawer _double;
	BorderFactory() :_null(), _single(), _double() {}
public:
	BorderDrawer& getNull() { return _null; }
	BorderDrawer& getSingle() { return _single; }
	BorderDrawer& getDouble() { return _double; }
	static BorderFactory& instance() { static BorderFactory instance; return instance; }
	BorderFactory(const BorderFactory& ) = delete;
	void operator=(const BorderFactory&) = delete;

};