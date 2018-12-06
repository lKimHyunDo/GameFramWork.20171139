#include "PocketBallTable.h"
#include "TextureManager.h"
#include "Game.h"

PocketBallTable::PocketBallTable(LoaderParams * pLoaderParams) :
	SDLGameObject(pLoaderParams)
{
}

void PocketBallTable::draw()
{
	TextureManager::Instance()->draw(m_textureID,
		m_position.getX() - m_width / 2.f,
		m_position.getY() - m_height / 2.f,
		m_width, m_height, TheGame::Instance()->getRenderer());
}
