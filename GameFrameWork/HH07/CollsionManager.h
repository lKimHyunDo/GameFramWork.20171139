#pragma once
class GameObject;

class CollisionManager
{
private:
	CollisionManager() {}
	static CollisionManager* s_pInstance;
public:
	static CollisionManager* Instance() {
		if (s_pInstance == 0)
		{
			s_pInstance = new CollisionManager();
		}
		return s_pInstance;
	}

private:

public:
	bool RectCollsion(GameObject* pCollider1, GameObject* pCollider2);
};