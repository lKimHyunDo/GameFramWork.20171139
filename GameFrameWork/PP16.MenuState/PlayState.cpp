#include <iostream>
#include "PlayState.h"
#include "SDLGameObject.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "GameStateMachine.h"
#include "PauseState.h"
#include "Game.h"

PlayState* PlayState::s_pInstance = 0;
const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	if (TheInputHandler::Instance()->isKeyDown(
		SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->changeState(
			PauseState::Instance());
		
	}
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter()
{
	if (!TheTextureManager::Instance()->load(
		"assets/helicopter.png", "helicopter",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}


	GameObject* player = new Player(
		new LoaderParams(100, 100, 128, 55, "helicopter"));
	m_gameObjects.push_back(player);
	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	std::cout << "exiting PlayState\n";
	return true;
}