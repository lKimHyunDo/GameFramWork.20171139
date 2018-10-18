#pragma once

#include "SDL.h"

#include "GameObject.h"
#include "Player.h"
#include "TextureManager.h"

class Game
{
private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

	int m_currentFrame;

	GameObject m_go;
	Player m_player;

public:
	Game() {}
	virtual ~Game() {}
	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);

	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }
};