#pragma once
#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
private:
	int m_numFrames;

private:
	void handleInput();
public:
	Enemy(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};