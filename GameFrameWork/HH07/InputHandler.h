#pragma once

#include <SDL.h>
#include <vector>

class Vector2D;

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}

	void update();
	void clean();  // ����̽� ���� �ʱ�ȭ�� �κ��� clear 

				   //bool isKeyDown(SDL_Scancode key);

	bool isKeyUp(SDL_Scancode key);
	bool isKeyDown(SDL_Scancode key);
	bool isKeyHolding(SDL_Scancode key);

	bool getMouseButtonState(int buttonNumber);
	Vector2D* getMousePosition();

private:
	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);

	void onKeyUp(SDL_Event& event);
	void onKeyDown(SDL_Event& event);

private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;

	const Uint8* m_keystates;

	bool m_isKeyUp[513] = { false };
	bool m_isKeyDown[513] = { false };
	bool m_isKeyHolding[513] = { false };

	int m_keyDownCheck;
	int m_keyUpCheck;

	// mouse buttion events								
	std::vector<bool> m_mouseButtonStates;

	// mouse motion event					
	Vector2D* m_mousePosition;



};


typedef InputHandler TheInputHandler;