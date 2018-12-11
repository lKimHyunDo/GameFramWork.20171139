#pragma once

#include "SDLGameObject.h"

class Table : public SDLGameObject
{
public:
	Table(LoaderParams* pLoaderParams);
private:
	virtual void draw();
};