#pragma once

class SDLGameObject;

class Collider
{
private:
	SDLGameObject* m_pGameObject;
	float m_radius = 0.f;
	bool m_enable = true;

public:
	Collider(SDLGameObject* pGameObject, float radius);
	~Collider();

	friend class CollisionManager;

	void SetCollsionRange(float radius) {
		m_radius = radius;
	}
	void setEnable(bool b){
		m_enable = b;
	}
};