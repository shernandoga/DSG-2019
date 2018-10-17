#pragma once
#include "Sprite.h"
class Projectile : public Sprite
{
	bool m_right;
	double m_x = 0.0, m_y = 0.0;
	float m_r, m_g, m_b;
	double m_depth = 1.0; // the renderer draws depths in range [1.0,20.0]
	double m_size = 1.0; //size of the quad
	double m_angle = 0.0; //rotation angle

public:
	Projectile(double coordPlayerX, double coordPlayerY, bool direction);
	~Projectile();
	void draw();
	void Projectile::setPosition(double x, double y, bool direction);
};



