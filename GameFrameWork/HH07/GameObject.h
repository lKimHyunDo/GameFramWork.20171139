#pragma once

#include <SDL.h>

#include "LoaderParams.h"

class GameObject
{
protected:
	string tag;
public:
	virtual void draw() = 0;
	virtual void collision(GameObject* pCollider) = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
protected:
	GameObject(const LoaderParams* pParams) {}
	virtual ~GameObject() {}
};
