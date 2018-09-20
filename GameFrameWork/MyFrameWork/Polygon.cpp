#include "Polygon.h"

void Polygon::SetPoly(Vec3 * arrVec, byte r, byte g, byte b)
{
	for (int i = 0; i < 3; i++)
	{
		vertex[i] = *(arrVec + i);
	}
	color.r = r; color.g = g; color.b = b;	
	brightness = 1;
}

void Polygon::SetNormalVec()
{
	Vec3 temp = Vec3::Cross(vertex[1] - vertex[0], vertex[3] - vertex[0]);
	temp.Normalize();
	normalVec = temp;
}

void Polygon::RotateX(float angle)
{
	for (int i = 0; i < 3; i++)
	{
		vertex[i].RotateX(angle);
	}
	normalVec.RotateX(angle);
}

void Polygon::RotateY(float angle)
{
	for (int i = 0; i < 3; i++)
	{
		vertex[i].RotateY(angle);
	}
	normalVec.RotateY(angle);
}

void Polygon::RotateZ(float angle)
{
	for (int i = 0; i < 3; i++)
	{
		vertex[i].RotateZ(angle);
	}
	normalVec.RotateZ(angle);
}
