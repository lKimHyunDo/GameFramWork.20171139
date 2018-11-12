#include "InputHandler.h"
#include "Game.h"
#include "Vector2D.h"
InputHandler* InputHandler::s_pInstance = 0;

InputHandler::InputHandler()
{
	m_keystates = NULL;
	// 생성자 
	m_mousePosition = new Vector2D(0, 0);
	for (int i = 0; i < 3; i++)
	{
		m_mouseButtonStates.push_back(false);
	}
}

void InputHandler::onMouseMove(SDL_Event & event)
{
	m_mousePosition->setX(event.motion.x);
	m_mousePosition->setY(event.motion.y);
}

void InputHandler::onMouseButtonDown(SDL_Event & event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		m_mouseButtonStates[LEFT] = true;
	}
	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouseButtonStates[MIDDLE] = true;
	}
	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouseButtonStates[RIGHT] = true;
	}
}

void InputHandler::onMouseButtonUp(SDL_Event & event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		m_mouseButtonStates[LEFT] = false;
	}
	if (event.button.button == SDL_BUTTON_MIDDLE)
	{
		m_mouseButtonStates[MIDDLE] = false;
	}
	if (event.button.button == SDL_BUTTON_RIGHT)
	{
		m_mouseButtonStates[RIGHT] = false;
	}

}

void InputHandler::onKeyUp(SDL_Event& event)
{
	if (m_isKeyHolding[event.key.keysym.scancode] == true) {
		m_isKeyUp[event.key.keysym.scancode] = true;
		m_keyUpCheck = event.key.keysym.scancode;
	}
	m_isKeyHolding[event.key.keysym.scancode] = false;
	//m_keystates = SDL_GetKeyboardState(0);
}

void InputHandler::onKeyDown(SDL_Event& event)
{
	if (m_isKeyHolding[event.key.keysym.scancode] == false) {
		m_isKeyDown[event.key.keysym.scancode] = true;
		m_keyDownCheck = event.key.keysym.scancode;
	}

	m_isKeyHolding[event.key.keysym.scancode] = true;
	//m_keystates = SDL_GetKeyboardState(0);
}

void InputHandler::clean()
{
	// 향후 추가 
}

void InputHandler::update()
{
	SDL_Event event;

	m_isKeyDown[m_keyDownCheck] = false;
	m_isKeyUp[m_keyUpCheck] = false;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			onMouseMove(event);
			break;
		case SDL_MOUSEBUTTONDOWN:
			onMouseButtonDown(event);
			break;
		case SDL_MOUSEBUTTONUP:
			onMouseButtonUp(event);
			break;
		case SDL_KEYDOWN:
			onKeyDown(event);
			break;
		case SDL_KEYUP:
			onKeyUp(event);
			break;
		default:
			break;
		}

	}

}

bool InputHandler::isKeyUp(SDL_Scancode key)
{
	return m_isKeyUp[key];
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	//if (m_keystates != 0) {
	//	if (m_keystates[key] == 1)
	//	{
	//		return true;
	//	}
	//	else {
	//		return false;
	//	}
	//}
	//return false;
	return 	m_isKeyDown[key];
}

bool InputHandler::isKeyHolding(SDL_Scancode key)
{
	return m_isKeyHolding[key];
}

bool InputHandler::getMouseButtonState(int buttonNumber)
{
	return m_mouseButtonStates[buttonNumber];
}

Vector2D * InputHandler::getMousePosition()
{
	return m_mousePosition;
}
