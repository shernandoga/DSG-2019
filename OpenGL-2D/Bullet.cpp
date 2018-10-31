#include "Bullet.h"
#include "Renderer.h"
#include <math.h>



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


		for (int x = 0; x < Renderer::get()->numPrintedObjects(); x++)
		{
			
			Sprite* theEnemy = (Sprite*)Renderer::get()->getDrawable(string("enemy") + to_string(x)); //get the instance called "enemyX"
			float distance = sqrt(pow((theEnemy->getX() - m_x),2) + pow((theEnemy->getY() - m_y), 2)); //magic formula to calculate the distance
			if (distance < (theEnemy->getSize()+ m_size)) {
				//collision!!
				//borrar theEnemy del vector<> que tiene renderer
				//sumar un punto
				//borrar la bala (llamar a delSprite) 
				
			}
		

		}

	
	
	
	}
}

void Bullet::draw() {
	/*if (m_hasImpact) {
		 Bullet();
	} */
	setPos(getPosX(),getPosY()+0.01);
	AnimatedSprite::draw();
}