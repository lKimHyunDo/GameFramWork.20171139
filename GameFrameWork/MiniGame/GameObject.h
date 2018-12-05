#pragma once

#include <SDL.h>
#include <string>
#include "LoaderParams.h"

class GameObject
{
public:
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
	std::string GetTag() { return m_tag; }
protected:
	GameObject(const LoaderParams* pParams) {}
	virtual ~GameObject() {}
	
	std::string m_tag;
};
