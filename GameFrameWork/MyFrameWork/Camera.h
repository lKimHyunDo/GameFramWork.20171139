#pragma once

#include "Vec3.h"

class Camera
{
private:
	Vec3 pos = { 0,0,0 };
	float dist;

	float angleX = 0.0f;
	float angleY = 0.0f;

	int width;
	int height;
public:
	Camera(int w,int h,float dist) {
		width = w; height = h; this->dist = dist;
	}
	~Camera() {}

	Vec3 GetPos()  { return pos; }
	float GetDist() { return dist; }
	float GetAngleX() { return angleX; }
	float GetAngleY() { return angleY; }	
	int GetWidth() { return width; }
	int GetHeight() { return height; }

	void SetAngleX(float angle) {
		this->angleX = angle;
	}
	void SetAngleY(float angle) {
		this->angleY = angle;
	}
	void SetPos(Vec3 pos) {
		this->pos = pos;
	}

};