#include <iostream>
#include "PlayState.h"
#include "SDLGameObject.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "GameStateMachine.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "Ball.h"
#include "WhiteBall.h"
#include "Game.h"

PlayState* PlayState::s_pInstance = 0;
const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	GameState::update();
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->changeState(
			PauseState::Instance());
	}
}

void PlayState::render()
{
	GameState::render();
}

bool PlayState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/white_ball.png", 
		"white_ball", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/red_ball.png",
		"red_ball", TheGame::Instance()->getRenderer())) {
		return false;
	}

	GameObject* ball = new WhiteBall(new LoaderParams(100, 100, 32, 32, "white_ball"));
	GameObject* ball2 = new Ball(new LoaderParams(200, 200, 32, 32, "red_ball"));
	GameObject* ball3 = new Ball(new LoaderParams(200, 100, 32, 32, "red_ball"));
	GameObject* ball4 = new Ball(new LoaderParams(100, 300, 32, 32, "red_ball"));
	GameObject* ball5 = new Ball(new LoaderParams(400, 200, 32, 32, "red_ball"));

	m_gameObjects.push_back(ball);
	m_gameObjects.push_back(ball2);
	m_gameObjects.push_back(ball3);
	m_gameObjects.push_back(ball4);
	m_gameObjects.push_back(ball5);
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