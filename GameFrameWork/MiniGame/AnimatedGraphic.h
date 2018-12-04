#pragma once

#include "SDLGameObject.h"

class LoaderParams;

class AnimatedGraphic : public SDLGameObject
{
private:
	int m_animSpeed;
	int m_numFrames;

public:
	AnimatedGraphic(const LoaderParams* pParams, int animSpeed);
	
	virtual void update();
};