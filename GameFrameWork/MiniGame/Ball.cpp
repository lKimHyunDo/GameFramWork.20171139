#include "Ball.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "Game.h"

Ball::Ball(const LoaderParams* pParams) :
	SDLGameObject(pParams), m_collider(this, m_width / 2.f)
{
	m_enable = true;
	m_radius = m_width / 2.f;
	m_tag = "ball";
}

void Ball::update()
{
	if (m_enable)
	{
		m_velocity += m_dVelocity;
		SDLGameObject::update();
		friction();
		m_dVelocity = { 0.f,0.f };

		if (m_position.getX() < 208.f + 16.f)
		{
			m_velocity.setX(-m_velocity.getX());
			m_position.setX(208.f + 16.f);
		}
		else if (m_position.getX() > 592.f - 16.f)
		{
			m_velocity.setX(-m_velocity.getX());
			m_position.setX(592.f - 16.f);
		}
		if (m_position.getY() < 55.f + 16.f)
		{
			m_velocity.setY(-m_velocity.getY());
			m_position.setY(55.f + 16.f);
		}
		else if (m_position.getY() > 647.f - 16.f)
		{
			m_velocity.setY(-m_velocity.getY());
			m_position.setY(647.f - 16.f);
		}
	}
}

void Ball::draw()
{
	if (m_enable)
	{
		TextureManager::Instance()->draw(m_textureID,
			m_position.getX() - m_width / 2.f,
			m_position.getY() - m_height / 2.f,
			m_width, m_height, TheGame::Instance()->getRenderer());
	}
}

void Ball::collision(SDLGameObject* other)
{
	if (m_enable)
	{
		if (other->GetTag() == "ball")
		{
			//공끼리 곂치지 않게 하는 코드
			Vector2D dir = other->getPosition() - m_position;
			float dist = dir.length();
			dir.normalize();
			if (dist < dynamic_cast<Ball*>(other)->getRadius() + m_radius)
			{
				dist = dynamic_cast<Ball*>(other)->getRadius() + m_radius - dist;
				other->addPosition(dir*dist / 2.f);
				m_position -= dir * dist / 2.f;
			}

			//충돌 코드
			Vector2D normal_velocity = m_velocity;
			normal_velocity.normalize();
			Vector2D vertical;
			vertical = { dir.getY(),-dir.getX() };

			//float theta = normal_velocity.getX()*dir.getX() + normal_velocity.getY()*dir.getY();
			float theta = normal_velocity.getX()*vertical.getX() + normal_velocity.getY()*vertical.getY();
			if (theta < 0)
			{
				vertical = { -dir.getY(), dir.getX() };
				theta = normal_velocity.getX()*vertical.getX() + normal_velocity.getY()*vertical.getY();
			}
			//theta = acosf(theta);
			//Vector2D vec = { m_velocity.getX()*cosf(theta), m_velocity.getY()*sinf(theta) };
			normal_velocity *= theta * m_velocity.length();
			m_dVelocity += (normal_velocity - m_velocity);

			theta = 1 - theta;
			//vec = { m_velocity.getX()*cosf(theta), m_velocity.getY()*sinf(theta) };
			dir *= theta * m_velocity.length();
			//other->RefVelocity() += vec;
			//m_velocity -= vec;
			dynamic_cast<Ball*>(other)->addDVelocity(dir);
		}
	}
}

void Ball::clean()
{

}

void Ball::friction()
{
	m_velocity -= m_velocity / 100.f;
}

void Ball::disable()
{
	m_enable = false;
	m_collider.setEnable(false);
}
