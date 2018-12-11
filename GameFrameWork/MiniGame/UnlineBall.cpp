#include "UnlineBall.h"

int UnlineBall::m_sNum = 0;

UnlineBall::UnlineBall(const LoaderParams * pLoaderParams):
	Ball::Ball(pLoaderParams)
{
	m_sNum++;
}

void UnlineBall::draw()
{
	Ball::draw();
}

void UnlineBall::update()
{
	Ball::update();
}

void UnlineBall::collision(SDLGameObject * other)
{
	Ball::collision(other);
	if (other->GetTag() == "hole")
	{
		disable();
	}
}

void UnlineBall::clean()
{
}

void UnlineBall::disable()
{
	Ball::disable();
	m_sNum--;
}
