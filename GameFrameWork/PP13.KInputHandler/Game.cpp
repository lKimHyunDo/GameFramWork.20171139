#include <iostream>
#include "Game.h"
#include "InputHandler.h"

Game* Game::s_pInstance = 0;
bool Game::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title,
			xpos, ypos,
			width, height, SDL_WINDOW_SHOWN && fullscreen);
	}

	if (m_pWindow != 0)
	{
		m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
	}
	else
	{
		m_bRunning = false;
		return false;
	}

	SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);

	TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer);

	m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
	m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));

	//m_go = new GameObject();
	//m_player = new Player();
	//m_enemy = new Enemy();
	//
	//m_go->load(100, 100, 128, 82, "animate");
	//m_player->load(300, 300, 128, 82, "animate");
	//m_enemy->load(0, 0, 128, 82, "animate");
	//
	//m_gameObjects.push_back(m_go);
	//m_gameObjects.push_back(m_player);
	//m_gameObjects.push_back(m_enemy);


	m_bRunning = true;
	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); // clear to the draw colour
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	SDL_RenderPresent(m_pRenderer); // draw to the screen

}

void Game::update()
{
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void Game::handleEvents()
{
	TheInputHandler::Instance()->update();
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	TheInputHandler::Instance()->clean();
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::quit()
{
	m_bRunning = false;
}
