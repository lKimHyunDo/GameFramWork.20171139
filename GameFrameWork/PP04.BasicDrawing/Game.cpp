
#include <iostream>
#include "Game.h"

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
	
	//Surface ↔ Texture 
	//Surface는 PC의 램에 올라가지만 Texture는 그래픽카드 메모리에 올라가기 때문에 더 빠르다.
	//또한 Surface는 이미지에 대한 정보(크기, 픽셀등)를 담고 있는 구조체 이지만
	//Texture는 단순히 그래픽 메모리 상의 주로를 가리키는 포인터이다.
	SDL_Surface* pTempSurface = SDL_LoadBMP("assets/rider.bmp");
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer,
		pTempSurface);

	SDL_FreeSurface(pTempSurface);

	SDL_QueryTexture(m_pTexture, NULL, NULL,
		&m_sourceRectangle.w, &m_sourceRectangle.h);

	m_bRunning = true;
	return true;
}

void Game::render()
{
	m_destnationRectangle.x = m_sourceRectangle.x = 0;
	m_destnationRectangle.y = m_sourceRectangle.y = 0;
	m_destnationRectangle.w = m_sourceRectangle.w;
	m_destnationRectangle.h = m_sourceRectangle.h;

	SDL_RenderClear(m_pRenderer);
	SDL_RenderCopy(m_pRenderer, m_pTexture,
		&m_sourceRectangle, &m_destnationRectangle);
	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::render()
{
	m_destnationRectangle.x = m_sourceRectangle.x = 0;
	m_destnationRectangle.y = m_sourceRectangle.y = 0;
	m_destnationRectangle.w = m_sourceRectangle.w;
	m_destnationRectangle.h = m_sourceRectangle.h;

	SDL_RenderClear(m_pRenderer);
	SDL_RenderCopy(m_pRenderer, m_pTexture,
		&m_sourceRectangle, &m_destnationRectangle);
	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}
