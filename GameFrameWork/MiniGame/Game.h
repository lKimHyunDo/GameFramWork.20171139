#pragma once

#include <vector>

#include "SDL.h"

#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "TextureManager.h"

class GameStateMachine;

class Game
{
private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

	int m_currentFrame;

	GameStateMachine* m_pGameStateMachine;

private:
	Game() {}
	// create the s_pInstance member variable
	static Game* s_pInstance;

public:
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
		}
		return s_pInstance;
	}

public:
	~Game() {}
	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);

	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }

	void quit();

	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }
	SDL_Renderer* getRenderer() const { return m_pRenderer; }
};

// create the typedef
typedef Game TheGame;