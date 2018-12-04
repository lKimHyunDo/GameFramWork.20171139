#pragma once

#include "GameState.h"

class SDLGameObject;

class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);
	virtual std::string getStateID() const { return s_playID; }

	static PlayState* Instance(){
		if (s_pInstance == 0)
			s_pInstance = new PlayState;
		return s_pInstance;
	}

private:
	static const std::string s_playID;
	static PlayState* s_pInstance;
	PlayState() {}
};