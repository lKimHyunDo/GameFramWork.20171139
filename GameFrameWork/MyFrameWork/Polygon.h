#pragma once

#include "Vec3.h"

struct Polygon
{
public:
	Vec3 vertex[3];
	Color color;
	Vec3 normalVec;
	float brightness;

public:
	Polygon() {}
	Polygon(Vec3* arrVec, byte r, byte g, byte b)
	{
		SetPoly(arrVec, r, g, b);
	}

	void operator += (Vec3 vec)
	{
		for (int i = 0; i < 3; i++)
		{
			vertex[i] += vec;
		}
	}
	void operator -= (Vec3 vec)
	{
		for (int i = 0; i < 3; i++)
		{
			vertex[i] -= vec;
		}
	}

	void SetPoly(Vec3* arrVec, byte r, byte g, byte b);
	void SetNormalVec();

	void RotateX(float angle);
	void RotateY(float angle);
	void RotateZ(float angle);
};