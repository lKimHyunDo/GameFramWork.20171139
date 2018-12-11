#include "LineBall.h"

int LineBall::m_sNum = 0;

LineBall::LineBall(const LoaderParams * pLoaderParams):
	Ball(pLoaderParams)
{
	m_sNum++;
}

void LineBall::draw()
{
	Ball::draw();
}

void LineBall::update()
{
	Ball::update();
}

void LineBall::collision(SDLGameObject * other)
{
	Ball::collision(other);
	if (other->GetTag() == "hole")
	{
		disable();
	}
}

void LineBall::clean()
{
}

void LineBall::disable()
{
	Ball::disable();
	m_sNum--;
}
