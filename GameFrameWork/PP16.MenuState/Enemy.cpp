#include "Enemy.h"
#include "InputHandler.h"

void Enemy::handleInput()
{
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		m_velocity.setX(1);
	}
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position) / 100;
}

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Enemy::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Enemy::update()
{
	handleInput();
	//m_position.setX(m_position.getX() + m_velocity.getX());
	//m_position.setY(m_position.getY() + m_velocity.getX());
	SDLGameObject::update();
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}
void Enemy::clean()
{
}