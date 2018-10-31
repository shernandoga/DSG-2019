#include "Bullet.h"



Bullet::Bullet(double x, double y, const char* texture)
	:AnimatedSprite(texture,5, 2, true)
{
	//int m_direction; //0=UP/1=DOWN
	bool m_hasImpact = false;
	m_x=x;
	m_y=y;

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
	if (!m_hasImpact) {

		m_hasImpact = true; 
	
	
	
	}
}

void Bullet::draw() {
	/*if (m_hasImpact) {
		 Bullet();
	} */
	setPos(getPosX(),getPosY()+0.01);
	AnimatedSprite::draw();
}