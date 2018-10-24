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
	Sprite* pBullet = new Bullet(m_x, m_y, "img/alien-01.png");
	Renderer render;
	render.get()->addObject(pBullet);

}

