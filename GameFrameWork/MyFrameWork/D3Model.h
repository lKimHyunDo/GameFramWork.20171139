#pragma once

#include "Polygon.h"

struct D3Model
{
public:
	Polygon * arrPoly = 0;
	int nPoly = 0;

public:
	D3Model() {}
	D3Model(D3Model& model)
	{
		if (model.arrPoly == 0)
			return;
		nPoly = model.nPoly;
		arrPoly = new Polygon[nPoly];
		for (int i = 0; i < nPoly; i++)
		{
			arrPoly[i] = model.arrPoly[i];
		}
	}
	
	void operator += (Vec3 vec)
	{
		for (int i = 0; i < nPoly; i++)
		{
			arrPoly[i] += vec;
		}
    }
	void operator -= (Vec3 vec)
	{
		for (int i = 0; i < nPoly; i++)
		{
			arrPoly[i] -= vec;
		}
	}

	void SetCube(Vec3 center,Vec3 size,byte r,byte g, byte b);

	void RotateX(float angle);
	void RotateY(float angle);
	void RotateZ(float angle);
};