#include "Projectile.h"
#include "stdafx.h"



Projectile::Projectile(double coordPlayerX, double coordPlayerY, bool direction)
{
	this->setColor(255, 0, 0);
	setPosition(coordPlayerX, coordPlayerY, direction);
	this->setRotation(0.0);
	this->setSize(0.2);
	this->setDepth(1.5);
	//renderer.addObject(this);
	draw();
}

Projectile::~Projectile()
{
}

void Projectile::setPosition(double x, double y, bool direction)
{
	m_x = x;
	m_y = y;
	m_right = direction;
}

void Projectile::draw()
{
	//1. Pass the object's color to OpenGL

	glColor3f(m_r, m_g, m_b);

	//2. Save the current transformation matrix

	glPushMatrix();

	//3. Set the transformation matrix of the quad using position, size and angle

	glTranslatef(m_x, m_y, 0);
	glRotatef(m_angle, 0, 0, 1);
	glScalef(m_size, m_size, 1);

	//4. Draw the quad centered in [0,0] with coordinates: [-1,-1], [1,-1], [1,1] and [-1,1]

	glBegin(GL_QUADS);
	glVertex3f(-1, -1, -m_depth);
	glVertex3f(1, -1, -m_depth);
	glVertex3f(1, 1, -m_depth);
	glVertex3f(-1, 1, -m_depth);
	glEnd();

	//5. Restore the transformation matrix

	glPopMatrix();
	
}
