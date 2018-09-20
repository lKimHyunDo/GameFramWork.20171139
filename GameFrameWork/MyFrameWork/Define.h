#pragma once

typedef unsigned char byte;

struct Vec2
{
	float x, y;
};

struct Color
{
public:
	byte r, g, b;

	void operator * (float a)
	{
		if (a >= 0 && a <= 1)
		{
			r *= a;
			g *= a;
			b *= a;
		}
	}
};

enum RenderFlage
{
	polygon_line = 0x00000001,
	surface		 = 0x00000002,
	cullof		 = 0x00000008,	
};