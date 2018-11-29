#pragma once

#include<string>
#include <vector>

class GameObject;

class GameState
{
protected:
	std::vector<GameObject*> m_gameObjects;
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;
	virtual std::string getStateID() const = 0;
};