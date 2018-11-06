#include "CollsionManager.h"
#include "SDLGameObject.h"

CollisionManager* CollisionManager::s_pInstance = 0;

bool CollisionManager::RectCollsion(GameObject * pCollider1, GameObject * pCollider2)
{
	float left1, top1, right1, botton1;
	float left2, top2, right2, botton2;

	left1 = ((SDLGameObject*)pCollider1)->GetPos().getX();
	left2 = ((SDLGameObject*)pCollider2)->GetPos().getX();

	top1 = ((SDLGameObject*)pCollider1)->GetPos().getY();
	top2 = ((SDLGameObject*)pCollider2)->GetPos().getY();

	right1 = ((SDLGameObject*)pCollider1)->GetPos().getX() + ((SDLGameObject*)pCollider1)->GetWidth();
	right2 = ((SDLGameObject*)pCollider2)->GetPos().getX() + ((SDLGameObject*)pCollider2)->GetWidth();

	botton1 = ((SDLGameObject*)pCollider1)->GetPos().getY() + ((SDLGameObject*)pCollider1)->GetHeight();
	botton2 = ((SDLGameObject*)pCollider2)->GetPos().getY() + ((SDLGameObject*)pCollider2)->GetHeight();

	if (left1 < right2 &&
		top1 < botton2 &&
		right1 > left2 &&
		botton1 > top2)
		return true;
	else
		return false;
}
