#include "Ball.h"
#include "InputHandler.h"

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

void Ball::collision(GameObject * pCollision)
{
}

void Ball::update()
{
	m_velocity.setX(1);
	handleInput(); // add our function
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	SDLGameObject::update();
}
void Ball::clean()
{
}