#pragma once

#include "header.h"

struct Vec3
{
public:
	float x, y, z;

public:
	Vec3() {}
	Vec3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vec3 operator + (Vec3 vec)
	{
		Vec3 temp;
		temp.x = x + vec.x;
		temp.y = y + vec.y;
		temp.z = z + vec.z;
		return temp;
	}
	Vec3 operator - (Vec3 vec) {
		Vec3 temp;
		temp.x = x - vec.x;
		temp.y = y - vec.y;
		temp.z = z - vec.z;
		return temp;
	}
	Vec3 operator * (float f)
	{
		Vec3 temp;
		temp.x = x * f;
		temp.y = y * f;
		temp.z = z * f;
	}
	Vec3 operator / (float f)
	{
		Vec3 temp;
		temp.x = x / f;
		temp.y = y / f;
		temp.z = z / f;
	}
	void operator += (Vec3 vec) {
		x = x + vec.x;
		y = y + vec.y;
		z = z + vec.z;
	}
	void operator -= (Vec3 vec) {
		x = x - vec.x;
		y = y - vec.y;
		z = z - vec.z;
	}
	void operator *= (float f)
	{
		x = x * f;
		y = y * f;
		z = z * f;
	}
	void operator /= (float f)
	{
		x = x / f;
		y = y / f;
		z = z / f;
	}

	float Length();	
	void Normalize();
	
	//축회전
	void RotateX(float angle);
	void RotateY(float angle);
	void RotateZ(float angle);

	//외적
	static Vec3 Cross(Vec3 a, Vec3 b)
	{
		Vec3 temp;
		temp.x = a.y * b.z - a.z * b.y;
		temp.y = a.z * b.x - a.x * b.z;
		temp.z = a.x * b.y - a.y * b.x;
		return temp;
	}
};