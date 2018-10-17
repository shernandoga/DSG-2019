#pragma once
#include "Sprite.h"
class Bullet :
	public Sprite
{

	//int m_direction; //0=UP/1=DOWN
	bool m_hasImpact;

public:
	Bullet(double x,double y, const char* texture);
	~Bullet();

	//void moveUp();
	//void moveDown();

	double getPosX();
	double getPosY();

	void setPos(double x,double y);
	void changeImpact();


};




