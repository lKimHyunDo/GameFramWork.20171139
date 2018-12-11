#pragma once

#include "SDLGameObject.h"
#include "Collider.h"

class Hole : public SDLGameObject
{
private:
	Collider m_collider;

public:
	Hole(LoaderParams* pLoaderParams);
	virtual void draw();
};