#include "Collider.h"
#include "CollisionManager.h"
#include "SDLGameObject.h"

using namespace std;

Collider::Collider(SDLGameObject * pGameObject,float radius)
	: m_pGameObject(pGameObject),m_radius(radius)
{
	CollisionManager::Instance()->m_colliders.push_back(this);
}

Collider::~Collider()
{
	CollisionManager::Instance()->DestroyCollider(this);
}
