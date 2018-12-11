#include "Table.h"
#include "TextureManager.h"
#include "Game.h"

Table::Table(LoaderParams * pLoaderParams) :
	SDLGameObject(pLoaderParams)
{
}

void Table::draw()
{
	SDLGameObject::draw();
}
