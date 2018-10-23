#pragma once

#include <vector>

#include "SDL.h"

#include "GameObject.h"
#include "TextureManager.h"
#include "Monster.h"
class Game
{
private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

	int m_currentFrame;

	Monster* m_pMonster[2];

	std::vector<GameObject*> m_gameObjects;

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