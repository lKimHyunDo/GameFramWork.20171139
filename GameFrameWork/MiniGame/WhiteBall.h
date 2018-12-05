#pragma once

#include "Ball.h"

class Vector2D;

class WhiteBall : public Ball
{
private:
	Vector2D * m_pMousePos;
	bool m_isClicked;
	bool m_isDrag;

public:
	WhiteBall(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void collision(SDLGameObject* other);
	virtual void clean();

	bool isClicked();
	void addForce();
};