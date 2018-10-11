
#include "Game.h"

Game* Game::m_pInst = 0;

Vec2 prePos = { 0,0 };

bool Game::init(const char * title, int xpos, int ypos, 
	int width, int height, bool fullscreen)
{	
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		screenSizeW = width;
		screenSizeH = height;

		m_pWindow = SDL_CreateWindow("GameFrameWork",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			screenSizeW, screenSizeH, SDL_WINDOW_SHOWN && fullscreen);

		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}
		else
		{
			return false;
		}
		m_bRunning = true;

		//HWND handle = systemInfo.info.win.window;


		return true;

	}
	else {
		return false;
	}
}

void Game::Run()
{
	Start();
	while (m_bRunning)
	{
		HandleEvents();
		Update();
		LateUpdate();
		Render();
	}
	Clean();
}

void Game::Start()
{
	cam = new Camera(screenSizeW, screenSizeH, screenSizeH / 2);
	
	cube.SetCube(Vec3(25,25,25),Vec3(50,50,50),255,255,255);
	object.model = &cube;
	object.pos.z = -150;
}

void Game::HandleEvents()
{
	SDL_Event event;
	Vec3 x = { 5,0,0 };
	Vec3 y = { 0,5,0 };
	Vec3 z = { 0,0,5 };

	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_UP)
			{
				cam->SetAngleX(cam->GetAngleX() + 0.03f);
			}
			if (event.key.keysym.sym == SDLK_DOWN)
			{
				cam->SetAngleX(cam->GetAngleX() - 0.03f);
			}
			if (event.key.keysym.sym == SDLK_LEFT)
			{
				cam->SetAngleY(cam->GetAngleY() + 0.03f);
			}
			if (event.key.keysym.sym == SDLK_RIGHT)
			{
				cam->SetAngleY(cam->GetAngleY() - 0.03f);
			}

			if (event.key.keysym.sym == SDLK_w)
			{
				cam->SetPos(cam->GetPos() + z);
			}
			if (event.key.keysym.sym == SDLK_s)
			{
				cam->SetPos(cam->GetPos() - z);
			}
			if (event.key.keysym.sym == SDLK_a)
			{
				cam->SetPos(cam->GetPos() - x);
			}
			if (event.key.keysym.sym == SDLK_d)
			{
				cam->SetPos(cam->GetPos() + x);
			}
			if (event.key.keysym.sym == SDLK_z)
			{
				cam->SetPos(cam->GetPos() + y);
			}
			if (event.key.keysym.sym == SDLK_x)
			{
				cam->SetPos(cam->GetPos() - y);
			}
			break;
		//case SDL_MOUSEMOTION:
		//	cam->SetAngleX(cam->GetAngleX() + (event.motion.y - prePos.y)*0.003f);
		//	cam->SetAngleY(cam->GetAngleY() + (event.motion.x - prePos.x)*0.003f);
		//	prePos.x = event.motion.x;
		//	prePos.y = event.motion.y;
		//	break;
		default:
			break;
		}
	}
}

void Game::Update()
{
	object.angle.x += 0.001f;
	object.angle.y += 0.001f;
	object.angle.z += 0.001f;
}

void Game::LateUpdate()
{

}

void Game::Render()
{
	SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
	SDL_RenderClear(m_pRenderer);
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
	
	D3Render::GetInst()->RenderD3Object(m_pRenderer,*cam, object);

	
	SDL_RenderPresent(m_pRenderer);
}

void Game::Clean()
{
	delete cam;
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	D3Render::DeleteSingle();
	SDL_Quit();
}
