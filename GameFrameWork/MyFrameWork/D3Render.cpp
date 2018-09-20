
#include "D3Render.h"
#include "SDL2_gfxPrimitives.h"

D3Render* D3Render::m_pinst = 0;

Vec3 D3Render::WorldToCamera(Camera& cam,Vec3 ver)
{
	Vec3 temp = ver - cam.GetPos();
	temp.RotateY(cam.GetAngleY());
	temp.RotateX(cam.GetAngleX());
	return temp;
}


Vec2 D3Render::CameraToViewer(Camera& cam,Vec3 ver)
{
	Vec2 pos;
	if (ver.z == 0) {
		pos.x = ver.x;
		pos.y = ver.y;
	}
	else {
		float temp = cam.GetDist()*2 / ver.z;
		pos.x = ver.x * temp + cam.GetWidth()/2;
		pos.y = ver.y * temp + cam.GetHeight()/2;
	}

	return pos;
}

Vec2 D3Render::WorldToViewer(Camera & cam, Vec3 ver)
{
	return CameraToViewer(cam, WorldToCamera(cam, ver));
}

void D3Render::WorldToObject(D3Object & obj)
{
	obj.model->RotateX(obj.angle.x);
	obj.model->RotateY(obj.angle.y);
	obj.model->RotateZ(obj.angle.z);
	*obj.model -= obj.pos;
}

void D3Render::RenderD3Model(SDL_Renderer* pRender,Camera& cam, D3Model & model)
{
	Vec2 p[3];
	float b;
	for (int i = 0; i < model.nPoly; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			p[j] = WorldToViewer(cam, model.arrPoly[i].vertex[j]);
		}
		if (i % 2 == 0)
		{
			model.arrPoly[i].SetNormalVec();
			b = Brightness(model.arrPoly[i].normalVec);
		}
		if(!CullOff(p[0],p[1],p[2]))
			DrawPolygon(pRender, p, model.arrPoly[i].color, b);
		//SDL_RenderDrawLine(pRender, p[0].x, p[0].y, p[1].x, p[1].y);
		//SDL_RenderDrawLine(pRender, p[1].x, p[1].y, p[2].x, p[2].y);
		//SDL_RenderDrawLine(pRender, p[2].x, p[2].y, p[0].x, p[0].y);
	}
}

void D3Render::RenderD3Object(SDL_Renderer * pRender, Camera & cam, D3Object& obj)
{
	D3Model tempMod(*obj.model);
	D3Object tempObj = obj;
	tempObj.model = &tempMod;

	WorldToObject(tempObj);
	RenderD3Model(pRender, cam, *tempObj.model);

	delete[] tempMod.arrPoly;
}

void D3Render::DrawPolygon(SDL_Renderer* pRender,Vec2 * p, Color color, float b)
{
	Sint16 x[3] = { p[0].x,p[1].x,p[2].x };
	Sint16 y[3] = { p[0].y,p[1].y,p[2].y };
	filledPolygonRGBA(pRender, x, y, 3,color.r*b, color.g*b, color.b*b, 255);
}

float D3Render::Brightness(Vec3 nomalVec)
{
	Vec3 lightDir = { 1,1,1 };
	lightDir.Normalize();
	Vec3 a = nomalVec + lightDir;
	float s = sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
	s = 1 - s / 5;
	return s;
}

bool D3Render::CullOff(Vec2 a, Vec2 b, Vec2 c)
{
	int S;
	Vec2 Vx, Vy;

	Vx.x = a.x - b.x;
	Vx.y = a.y - b.y;
	Vy.x = c.x - b.x;
	Vy.y = c.y - b.y;

	S = Vx.x*Vy.y - Vx.y*Vy.x;
	if (S<0)
		return true;
	else
		return false;
}

