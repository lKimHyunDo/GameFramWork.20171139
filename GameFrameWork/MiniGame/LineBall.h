#pragma once

#include "Ball.h"

class LineBall : public Ball
{
private:
	static int m_sNum;

public:
	LineBall(const LoaderParams* pLoaderParams);
	virtual ~LineBall() {}
	virtual void draw();
	virtual void update();
	virtual void collision(SDLGameObject* other);
	virtual void clean();

	virtual void disable();

	static int getNum() {
		return m_sNum;
	}
	static void setNum(int i) {
		m_sNum = i;
	}
};
