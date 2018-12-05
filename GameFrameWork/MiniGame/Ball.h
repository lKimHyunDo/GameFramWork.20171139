#pragma once

#include "SDLGameObject.h"
#include "Collider.h"

class Ball : public SDLGameObject
{
private:
	Collider m_collider;
	float m_radius;
	bool m_isClicked;
	bool m_isDrag;

public:
	Ball(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void collision(SDLGameObject* other);
	virtual void clean();

	void friction();
	float getRadius() { return m_radius; }
};