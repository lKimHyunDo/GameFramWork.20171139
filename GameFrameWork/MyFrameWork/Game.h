#pragma once

#include "header.h"
#include "D3Render.h"
#include "SDL2_gfxPrimitives.h"

class Game
{
#pragma region Single
private:
	static Game * m_pInst;

public:
	static Game* GetInst() {
		if (m_pInst == 0)
			m_pInst = new Game();
		return m_pInst;
	}
	static void DeleteSingle() {
		if (m_pInst != 0)
			delete m_pInst;
	}
#pragma endregion

private:
	SDL_Window * m_pWindow = 0;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning = false;

	int screenSizeW, screenSizeH;

	Camera* cam;

	D3Model cube;
	D3Object object;

public:
	bool init(const char * title, int xpos, int ypos, 
		int width, int height, bool fullscreen);
	void Run();

private:
	void Start();
	void HandleEvents();
	void Update();
	void LateUpdate();
	void Render();
	void Clean();
};