#pragma once

#include "SDLGameObject.h"
#include "Collider.h"

class Ball : public SDLGameObject
{
private:
	Collider m_collider;
	float m_radius;

	Vector2D m_dVelocity = { 0.f,0.f };

public:
	Ball(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void collision(SDLGameObject* other);
	virtual void clean();

	void friction();
	float getRadius() { return m_radius; }

	void addDVelocity(Vector2D vec){
		m_dVelocity += vec;
	}
};