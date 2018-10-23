#include "Monster.h"


void Monster::update()
{	
	m_x += m_moveSpeed;
	m_moveCount++;
	if (m_moveCount > 100)
	{
		m_moveSpeed *= -1;
		m_moveCount = 0;
	}

	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}
