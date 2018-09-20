#pragma once

#include "header.h"
#include "Camera.h"
#include "D3Object.h"

class D3Render
{
#pragma region Single
private:
	static D3Render * m_pinst;
public:
	static D3Render * GetInst() {
		if (m_pinst == 0)
			m_pinst = new D3Render();
		return m_pinst;
	}
	static void DeleteSingle() {
		if (m_pinst != 0)
			delete m_pinst;
		m_pinst = 0;
	}
#pragma endregion

public:
	RenderFlage setting;

public:
	D3Render() {}
	~D3Render() {}

	Vec3 WorldToCamera(Camera& cam,Vec3 ver);
	Vec2 CameraToViewer(Camera& cam,Vec3 ver);
	Vec2 WorldToViewer(Camera& cam, Vec3 ver);

	void WorldToObject(D3Object& obj);

	void RenderD3Model(SDL_Renderer* pRender,Camera& cam, D3Model& model);
	void RenderD3Object(SDL_Renderer* pRender, Camera& cam, D3Object& obj);

	void DrawPolygon(SDL_Renderer* pRender,Vec2* p,Color color,float b);

	float Brightness(Vec3 nomalVec);
	bool CullOff(Vec2 a,Vec2 b,Vec2 c);
};