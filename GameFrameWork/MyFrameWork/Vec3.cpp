#include "Vec3.h"

float Vec3::Length()
{
	return sqrt(powf(x, 2.f) + powf(y, 2.f) + powf(z, 2.f));
}

void Vec3::Normalize()
{
	float f = this->Length();
	x /= f; y /= f; z /= f;
}

void Vec3::RotateX(float angle)
{
	float tempY = y;
	float tempZ = z;
	y = tempY * cosf(angle) + tempZ * sinf(angle);
	z = tempZ * cosf(angle) - tempY * sinf(angle);
}

void Vec3::RotateY(float angle)
{
	float tempX = x;
	float tempZ = z;
	x = tempX * cosf(angle) + tempZ * sinf(angle);
	z = tempZ * cosf(angle) - tempX * sinf(angle);
}

void Vec3::RotateZ(float angle)
{
	float tempX = x;
	float tempY = y;
	x = tempX * cosf(angle) + tempY * sinf(angle);
	y = tempY * cosf(angle) - tempX * sinf(angle);
}