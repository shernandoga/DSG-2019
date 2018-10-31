#include "Projectile.h"
#include "Renderer.h"
#include "stdafx.h"



Projectile::Projectile(double coordPlayerX, double coordPlayerY, bool direction,string dirimg)
:Sprite(dirimg)
{
	setColor(100, 0, 0);
	setPosition(coordPlayerX, coordPlayerY);
	setRotation(0.0);
	setSize(0.1);
	setDepth(1.5);
	m_right = direction;
	if(direction == true)
		setColor(130, 0, 0);
	else
		setColor(0, 130, 0);
}

Projectile::~Projectile()
{
}

void Projectile::draw()
{

	if (m_right == true)
	{
		m_x += 0.008;
	}

	if (m_right == false)
	{
		m_x -= 0.008;
	}

	if (m_x <= -1.0 || m_x >= 1.0 || m_y <= -1.0 || m_y >= 1.0)
		markForDeletion();
	else 
		Sprite::draw();
}
