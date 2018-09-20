#include <SDL.h>

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

SDL_Event g_Event;

int g_RectPosX = 0;
int g_RectPosY = 0;
void Update();

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		g_pWindow = SDL_CreateWindow("PP01.HelloSDL",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			640, 480, SDL_WINDOW_SHOWN);

		if (g_pWindow != 0)
		{
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}
		else
		{
			return 1;
		}

		while (1)
		{
			Update();			
		}
		
		SDL_Delay(1000);
		SDL_Quit();

		return 0;
	}
}

void Update()
{
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
	SDL_RenderClear(g_pRenderer);
	if (SDL_PollEvent(&g_Event))
	{
		if (g_Event.key.keysym.sym == SDLK_UP)
		{
			g_RectPosY -= 3;
		}
		if (g_Event.key.keysym.sym == SDLK_DOWN)
		{
			g_RectPosY += 3;
		}
		if (g_Event.key.keysym.sym == SDLK_LEFT)
		{
			g_RectPosX -= 3;
		}
		if (g_Event.key.keysym.sym == SDLK_RIGHT)
		{
			g_RectPosX += 3;
		}
		if (g_Event.key.keysym.sym == SDLK_ESCAPE)
		{
			SDL_Quit();
		}
	}

	SDL_SetRenderDrawColor(g_pRenderer, 255, 255, 255, 255);
	SDL_Rect rect = { g_RectPosX,g_RectPosY,50,50 };
	SDL_RenderDrawRect(g_pRenderer, &rect);


	SDL_RenderPresent(g_pRenderer);
}