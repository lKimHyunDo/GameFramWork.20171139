#include "Brick.h"
#include "InputHandler.h"
#include "TextureManager.h"
void Brick::handleInput()
{
}

Brick::Brick(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}//

void Brick::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}

void Brick::collision(GameObject * pCollider)
{
	if (pCollider->GetTag() == "ball")
	{
		m_textureID = "broken_brick";
	}
}

void Brick::update()
{
	m_velocity.setX(0);
	handleInput(); // add our function
	m_currentFrame = int(((SDL_GetTicks() / 100) % 1));
	SDLGameObject::update();
}
void Brick::clean()
{
}