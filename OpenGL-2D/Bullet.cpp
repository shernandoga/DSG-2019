#include "Bullet.h"



Bullet::Bullet(double x, double y, const char* texture)
	:Sprite(texture)
{
	//int m_direction; //0=UP/1=DOWN
	bool m_hasImpact = false;
	double m_x=x;
	double m_y=y;

}


Bullet::~Bullet()
{
}

//void moveUp();
//void moveDown();

double Bullet::getPosX() { return m_x; }
double Bullet::getPosY() { return m_y; }

void Bullet::setPos(double x, double y) { m_x = x; m_y = y; }

void Bullet::changeImpact() {
	if (!m_hasImpact) { m_hasImpact = true; }
}

void Bullet::draw() {
	setPos(getPosX(),getPosY()+0.001);
	Sprite::draw();
}