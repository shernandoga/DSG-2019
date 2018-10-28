#include "Player.h"
#include "stdafx.h"
#include "Bullet.h"
#include "Renderer.h"

Player::Player(string name, const char* texture): Sprite(texture)
{
	setPosition(0, -0.5);
	setSize(0.2);
	setDepth(1.25);
	setColor(255, 0, 0);
	setName(name);
}

void Player::shoot()
{

	Bullet* pBullet = new Bullet(m_x, m_y, "img/fire-animation-2.png");
	pBullet->setSize(0.1);
	Renderer::get()->addObject(pBullet);

}

