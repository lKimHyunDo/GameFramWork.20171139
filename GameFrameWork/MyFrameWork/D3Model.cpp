#include "D3Model.h"

void D3Model::SetCube(Vec3 center, Vec3 size,byte r, byte g, byte b)
{
	if (arrPoly != 0)
		return;

	arrPoly = new Polygon[12];

	Vec3 P[8];

	P[0].x = 0 - center.x;	    P[0].y = 0 - center.y;		P[0].z = 0 - center.z;
	P[1].x = size.x - center.x;	P[1].y = 0 - center.y;		P[1].z = 0 - center.z;
	P[2].x = 0 - center.x;		P[2].y = size.y - center.y;	P[2].z = 0 - center.z;
	P[3].x = size.x - center.x;	P[3].y = size.y - center.y;	P[3].z = 0 - center.z;
	P[4].x = 0 - center.x;		P[4].y = 0 - center.y;		P[4].z = size.z - center.z;
	P[5].x = size.x - center.x;	P[5].y = 0 - center.y;		P[5].z = size.z - center.z;
	P[6].x = 0 - center.x;		P[6].y = size.y - center.y;	P[6].z = size.z - center.z;
	P[7].x = size.x - center.x;	P[7].y = size.y - center.y;	P[7].z = size.z - center.z;

	/*	4	5
	6	7

		0	1
	2	3
	*/
	arrPoly[0].vertex[0] = P[0];
	arrPoly[0].vertex[1] = P[2];
	arrPoly[0].vertex[2] = P[1];

	arrPoly[1].vertex[0] = P[1];
	arrPoly[1].vertex[1] = P[2];
	arrPoly[1].vertex[2] = P[3];

	arrPoly[2].vertex[0] = P[4];
	arrPoly[2].vertex[1] = P[5];
	arrPoly[2].vertex[2] = P[6];

	arrPoly[3].vertex[0] = P[5];
	arrPoly[3].vertex[1] = P[7];
	arrPoly[3].vertex[2] = P[6];

	arrPoly[4].vertex[0] = P[6];
	arrPoly[4].vertex[1] = P[7];
	arrPoly[4].vertex[2] = P[2];

	arrPoly[5].vertex[0] = P[7];
	arrPoly[5].vertex[1] = P[3];
	arrPoly[5].vertex[2] = P[2];

	arrPoly[6].vertex[0] = P[7];
	arrPoly[6].vertex[1] = P[5];
	arrPoly[6].vertex[2] = P[3];

	arrPoly[7].vertex[0] = P[5];
	arrPoly[7].vertex[1] = P[1];
	arrPoly[7].vertex[2] = P[3];

	arrPoly[8].vertex[0] = P[5];
	arrPoly[8].vertex[1] = P[4];
	arrPoly[8].vertex[2] = P[1];

	arrPoly[9].vertex[0] = P[4];
	arrPoly[9].vertex[1] = P[0];
	arrPoly[9].vertex[2] = P[1];

	arrPoly[10].vertex[0] = P[4];
	arrPoly[10].vertex[1] = P[6];
	arrPoly[10].vertex[2] = P[0];

	arrPoly[11].vertex[0] = P[6];
	arrPoly[11].vertex[1] = P[2];
	arrPoly[11].vertex[2] = P[0];

	for (int i = 0; i < 12; i++)
	{
		arrPoly[i].color.r = r;
		arrPoly[i].color.g = g;
		arrPoly[i].color.b = b;
		arrPoly[i].SetNormalVec();
	}

	nPoly = 12;
}

void D3Model::RotateX(float angle)
{
	for (int i = 0; i < nPoly; i++)
	{
		arrPoly[i].RotateX(angle);
	}
}

void D3Model::RotateY(float angle)
{
	for (int i = 0; i < nPoly; i++)
	{
		arrPoly[i].RotateY(angle);
	}
}

void D3Model::RotateZ(float angle)
{
	for (int i = 0; i < nPoly; i++)
	{
		arrPoly[i].RotateZ(angle);
	}
}
