#include "BorderDrawer.h"

void DrawFrame(Graphics &g, int left, int top, int width, int height, char* frame)
{
	g.moveTo(left, top);
	DrawLine(width, frame[0], frame[1], frame[5]);
	for (int i = 0; i < height; ++i)
	{
		g.moveTo(left, ++top);
		DrawLine(width, frame[4], frame[4], ' ');
	}
	g.moveTo(left, ++top);
	DrawLine(width, frame[2], frame[3], frame[5]);
}

void DrawLine(int width, char left, char right, char mid)
{
	cout << left;
	for (int i = 0; i < width; ++i)
		cout << mid;
	cout << right;
}