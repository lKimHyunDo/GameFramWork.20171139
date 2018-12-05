#include "Ball.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "Game.h"

Ball::Ball(const LoaderParams* pParams) :
	SDLGameObject(pParams),m_collider(this,m_width/2.f)
{
	m_radius = m_width / 2.f;
	m_tag = "ball";
}

void Ball::update()
{
	SDLGameObject::update();
	friction();

	if (m_position.getX() < 30.f)
	{
		m_velocity.setX(-m_velocity.getX());
		m_position.setX(30.f);
	}
	else if (m_position.getX() > 470.f)
	{
		m_velocity.setX(-m_velocity.getX());
		m_position.setX(470.f);
	}
	if (m_position.getY() < 30.f)
	{
		m_velocity.setY(-m_velocity.getY());
		m_position.setY(30.f);
	}
	else if (m_position.getY() > 470.f)
	{
		m_velocity.setY(-m_velocity.getY());
		m_position.setY(470.f);
	}
}

void Ball::draw()
{
	TextureManager::Instance()->draw(m_textureID,
		m_position.getX() - m_width/2.f,
		m_position.getY() - m_height/2.f,
		m_width, m_height, TheGame::Instance()->getRenderer());
}

void Ball::collision(SDLGameObject* other)
{
	if (other->GetTag() == "ball")
	{
		//공끼리 곂치지 않게 하는 코드
		Vector2D dir = other->getPosition() - m_position;
		float dist = dir.length();
		dir.normalize();
		dist = ((Ball*)other)->getRadius() + m_radius - dist;
		other->addPosition(dir*dist);

		//탄성 충돌 코드
		Vector2D normal_velocity = m_velocity;
		normal_velocity.normalize();
		Vector2D vertical;
		vertical = { dir.getY(),-dir.getX() };
		float theta = normal_velocity.getX()*dir.getX() + normal_velocity.getY()*dir.getY();
		theta = acosf(theta);
		Vector2D vec = { m_velocity.getX()*cosf(theta), m_velocity.getY()*sinf(theta) };
		other->RefVelocity() += vec;
		m_velocity -= vec;
	}
}

void Ball::clean()
{

}

void Ball::friction()
{
	m_velocity -= m_velocity / 70.f;
}
