#include "WhiteBall.h"
#include "InputHandler.h"
#include "Game.h"

WhiteBall::WhiteBall(const LoaderParams * pParams) : Ball(pParams)
{
	m_pMousePos = TheInputHandler::Instance()->getMousePosition();
}

void WhiteBall::draw()
{
	Ball::draw();
	if (m_isDrag)
	{
		SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), 0, 0, 255, 255);
		SDL_RenderDrawLine(TheGame::Instance()->getRenderer(), m_position.getX(), m_position.getY(),
			m_pMousePos->getX(), m_pMousePos->getY());
		SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), 0, 0, 0, 255);
	}
}

void WhiteBall::update()
{
	m_isClicked = isClicked();
	if (m_isClicked == true)
		m_isDrag = true;
	if (m_isDrag == true && TheInputHandler::Instance()->getMouseButtonState(0) == false)
		addForce();
	if (TheInputHandler::Instance()->getMouseButtonState(0) == false)
		m_isDrag = false;
	Ball::update();

	if (TheInputHandler::Instance()->getMouseButtonState(0) == true)
	{
		cout << "x: " << TheInputHandler::Instance()->getMousePosition()->getX() <<
			" y: " << TheInputHandler::Instance()->getMousePosition()->getY() << endl;
	}
}

void WhiteBall::collision(SDLGameObject * other)
{
	Ball::collision(other);
	if (other->GetTag() == "hole")
	{
		disable();
	}
}

void WhiteBall::clean()
{
}

bool WhiteBall::isClicked()
{
	if (TheInputHandler::Instance()->getMouseButtonState(0))
	{
		if ((m_pMousePos->getX() > m_position.getX() - m_width / 2.f
			&& m_pMousePos->getX() < m_position.getX() + m_width / 2.f) &&
			(m_pMousePos->getY() > m_position.getY() - m_height / 2.f &&
				m_pMousePos->getY() < m_position.getY() + m_height / 2.f))
		{
			return true;
		}
	}
	return false;
}

void WhiteBall::addForce()
{
	Vector2D dir = m_position - *InputHandler::Instance()->getMousePosition();
	m_velocity += dir / 7.f;
}