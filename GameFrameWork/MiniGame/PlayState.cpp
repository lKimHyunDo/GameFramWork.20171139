#include <iostream>
#include "PlayState.h"
#include "SDLGameObject.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "GameStateMachine.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "LineBall.h"
#include "UnlineBall.h"
#include "WhiteBall.h"
#include "Table.h"
#include "Hole.h"
#include "CollisionManager.h"
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
	if (LineBall::getNum() <= 0 || UnlineBall::getNum() <= 0 || m_pWhiteBall->getEnable() == false)
	{
		TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
	}
}

void PlayState::render()
{
	GameState::render();
}

bool PlayState::onEnter()
{
	if (!TextureManager::Instance()->load("assets/table.png", "table",
		TheGame::Instance()->getRenderer()))
		return false;
	if (!TheTextureManager::Instance()->load("assets/white_ball.png",
		"white_ball", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/orange.png", 
		"orange_ball", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/red.png",
		"red_ball", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/purple.png",
		"purple_ball", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/line_orange.png",
		"line_orange_ball", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/line_red.png",
		"line_red_ball", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/line_purple.png",
		"line_purple_ball", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/hole.png",
		"hole", TheGame::Instance()->getRenderer())) {
		return false;
	}

	LineBall::setNum(0);
	UnlineBall::setNum(0);

	m_gameObjects.push_back(new Table(new LoaderParams(150, 0, 500, 700, "table")));
	m_pWhiteBall = new WhiteBall(new LoaderParams(400, 452, 32, 32, "white_ball"));
	m_gameObjects.push_back(m_pWhiteBall);
	m_gameObjects.push_back(new Hole(new LoaderParams(585, 56, 37, 37, "hole")));
	m_gameObjects.push_back(new Hole(new LoaderParams(211, 56, 37, 37, "hole")));
	m_gameObjects.push_back(new Hole(new LoaderParams(195, 352, 37, 37, "hole")));
	m_gameObjects.push_back(new Hole(new LoaderParams(607, 352, 37, 37, "hole")));
	m_gameObjects.push_back(new Hole(new LoaderParams(211, 641, 37, 37, "hole")));
	m_gameObjects.push_back(new Hole(new LoaderParams(585, 639, 37, 37, "hole")));
	srand(SDL_GetTicks());

	string textureId[6] = {
		"orange_ball","red_ball","purple_ball",
		"line_orange_ball","line_red_ball","line_purple_ball"
	};

	Vector2D ballPos[10];
	int idx = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i; j++)
		{
			ballPos[idx] = { 400.f + j * 32.f - i * 16.f, 260.f - i * 28.f };
			idx++;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		int a = rand() % 10;
		int b = rand() % 10;

		Vector2D temp = ballPos[a];
		ballPos[a] = ballPos[b];
		ballPos[b] = temp;

	}

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0) {
			m_gameObjects.push_back(new UnlineBall(new LoaderParams(
				ballPos[i].getX(), ballPos[i].getY(),
				32, 32,
				textureId[i%3])));
		}
		else {
			m_gameObjects.push_back(new LineBall(new LoaderParams(
				ballPos[i].getX(), ballPos[i].getY(),
				32, 32,
				textureId[i%3+3])));
		}

	}

	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();	
		delete m_gameObjects[i];
	}
	m_gameObjects.clear();
	CollisionManager::Instance()->Clear();

	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	std::cout << "exiting PlayState\n";
	return true;
}