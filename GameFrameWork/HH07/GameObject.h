#pragma once

#include <SDL.h>
#include "iostream"
#include "LoaderParams.h"

using namespace std;

class GameObject
{
protected:
	string m_tag;
public:
	virtual void draw() = 0;
	virtual void collision(GameObject* pCollider) = 0;
	virtual void update() = 0;
	virtual void clean() = 0;

	string GetTag() { return m_tag; }
protected:
	GameObject(const LoaderParams* pParams) {}
	virtual ~GameObject() {}
};
