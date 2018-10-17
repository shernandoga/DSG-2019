#include "Projectile.h"
#include "stdafx.h"



Projectile::Projectile(double coordPlayerX, double coordPlayerY, bool direction)
{
	setColor(100, 0, 0);
	setPosition(coordPlayerX, coordPlayerY);
	setRotation(0.0);
	setSize(0.2);
	setDepth(1.5);

	m_r = 210;
	m_g = 10;
	m_b = 10;



	//renderer.addObject(this);
	//draw();
}

Projectile::~Projectile()
{
}

void Projectile::draw()
{
	if (m_right == true) {

	}
	m_x += m_x * 0.0001;
	//m_y += m_y * 0.01;
	Sprite::draw();
	
}
