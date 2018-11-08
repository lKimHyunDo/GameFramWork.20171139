#include "Ball.h"
#include "InputHandler.h"
#include "Game.h"
#include <iterator>

void Ball::handleInput()
{
}

Ball::Ball(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Ball::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

void Ball::collision(GameObject * pCollider)
{
	if (pCollider->GetTag() == "brick")
	{
		vector<GameObject*>::iterator iter = Game::Instance()->GetGameObjects()->begin();
		vector<GameObject*>::iterator iterEnd = Game::Instance()->GetGameObjects()->end();
		for (; iter != iterEnd; iter++)
		{
			if (*iter == this) {
				Game::Instance()->GetGameObjects()->erase(iter);
				break;
			}
		}		
	}
}

void Ball::update()
{
	m_velocity.setX(5);
	handleInput(); // add our function
	m_currentFrame = int(((SDL_GetTicks() / 100) % 1));
	SDLGameObject::update();
}
void Ball::clean()
{
}