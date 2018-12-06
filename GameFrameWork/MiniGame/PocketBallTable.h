#pragma once

#include "SDLGameObject.h"

class PocketBallTable : public SDLGameObject
{
public:
	PocketBallTable(LoaderParams* pLoaderParams);
private:
	virtual void draw();
};