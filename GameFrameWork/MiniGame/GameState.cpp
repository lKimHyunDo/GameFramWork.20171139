#include "GameState.h"
#include "GameObject.h"
#include "CollisionManager.h"

void GameState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
	CollisionManager::Instance()->Update();
}

void GameState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}
