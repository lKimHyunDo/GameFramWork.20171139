#include "Player.h"
#include "InputHandler.h"
#include "Ball.h"
#include "Game.h"

void Player::handleInput()
{
	if (TheInputHandler::Instance()->isKeyHolding(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyHolding(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-2);
	}
	if (TheInputHandler::Instance()->isKeyHolding(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-2);
	}
	if (TheInputHandler::Instance()->isKeyHolding(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
	{
		Game::Instance()->GetGameObjects()->push_back(new Ball(new LoaderParams(m_position.getX()+82, m_position.getY()+30, 32, 32,"ball", "ball")));
	}
}

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Player::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

void Player::collision(GameObject * pCollision)
{
}

void Player::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput(); // add our function
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	SDLGameObject::update();
}
void Player::clean()
{
}