#pragma once
#include "GameObject.h"
class Monster : public GameObject
{
public:
	float m_moveSpeed = 1.f;
	int m_moveCount = 0;
public:
	void update();

	void SetMoveSpeed(float speed)
	{
		m_moveSpeed = speed;
	}
};