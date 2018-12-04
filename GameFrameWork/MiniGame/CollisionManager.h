#pragma once

#include <vector>

class Collider;

class CollisionManager
{
private:
	CollisionManager() {}
	static CollisionManager* s_pinst;

public:
	static CollisionManager* Instance() {
		if (s_pinst == 0)
			s_pinst = new CollisionManager();
		return s_pinst;
	}

private:
	std::vector<Collider*> m_colliders;

public:
	bool CollisionCheck(Collider* col1, Collider*col2);
	void Update();
	void Clear();
	void DestroyCollider(Collider* col);

	friend Collider;
};