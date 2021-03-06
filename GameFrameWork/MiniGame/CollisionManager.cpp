#include "CollisionManager.h"
#include "Collider.h"
#include "SDLGameObject.h"
#include <iterator>

CollisionManager* CollisionManager::s_pinst = 0;

bool CollisionManager::IsCollision(Collider * col1, Collider * col2)
{
	//원 충돌검사
	Vector2D dir = col1->m_pGameObject->getPosition() - col2->m_pGameObject->getPosition();
	

	float dist = dir.length();

	if (dist < col1->m_radius + col2->m_radius)
		return true;
	
	return false;
}

void CollisionManager::Update()
{
	for (int i = 0; i < ((int)m_colliders.size() - 1); i++)
	{
		for (int j = i + 1; j < (int)m_colliders.size(); j++)
		{
			if (m_colliders[i]->m_enable && m_colliders[j]->m_enable)
			{
				if (IsCollision(m_colliders[i], m_colliders[j]))
				{
					m_colliders[i]->m_pGameObject->collision(m_colliders[j]->m_pGameObject);
					m_colliders[j]->m_pGameObject->collision(m_colliders[i]->m_pGameObject);
				}
			}
		}
	}
}

void CollisionManager::Clear()
{
	m_colliders.clear();
}

void CollisionManager::DestroyCollider(Collider * col)
{
	vector<Collider*>::iterator iter = m_colliders.begin();
	vector<Collider*>::iterator iterEnd = m_colliders.end();

	for (; iter != iterEnd; iter++)
	{
		if (*iter == col)
		{
			m_colliders.erase(iter);
			return;
		}
	}
}
