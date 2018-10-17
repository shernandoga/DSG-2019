#include "Projectile.h"
#include "Renderer.h"
#include "stdafx.h"



Projectile::Projectile(double coordPlayerX, double coordPlayerY, bool direction)
{
	setColor(100, 0, 0);
	setPosition(coordPlayerX, coordPlayerY);
	setRotation(0.0);
	setSize(0.1);
	setDepth(1.5);
	setColor(210, 10, 10);
	m_right = direction;
}

Projectile::~Projectile()
{
}

void Projectile::draw()
{
	bool destr = false;

	if (m_right == true) 
	{
		m_x += m_x * 0.004;
	}

	if (m_right == false) 
	{
		m_x -= m_x * 0.004;
	}

	if (m_x <= -1.0 || m_x >= 1.0 || m_y <= -1.0 || m_y >= 1.0)
	{
		destr = true;
	}

	if(destr == false)
	{
		Sprite::draw();
	}
	else
	{
		Renderer::get()->removeObject(this);
	}
	
}
