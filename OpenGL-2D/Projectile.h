#pragma once
#include "Sprite.h"
class Projectile : public Sprite
{
protected:
	bool m_right;

public:
	Projectile(double coordPlayerX, double coordPlayerY, bool direction);
	~Projectile();
	void draw();
	bool isHitP1();
	bool isHitP2();
};



