#pragma once

#include "Ball.h"

class UnlineBall : public Ball
{
private:
	static int m_sNum;

public:
	UnlineBall(const LoaderParams* pLoaderParams);
	virtual ~UnlineBall() {}
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