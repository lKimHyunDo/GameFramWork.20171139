#include "Hole.h"
#include "TextureManager.h"
#include "Game.h"

Hole::Hole(LoaderParams * pLoaderParams):
	SDLGameObject(pLoaderParams),m_collider(this,m_width/2.f)
{
	m_tag = "hole";
}

void Hole::draw()
{
	TextureManager::Instance()->draw(m_textureID,
		m_position.getX() - m_width / 2.f,
		m_position.getY() - m_height / 2.f,
		m_width, m_height, TheGame::Instance()->getRenderer());
}
