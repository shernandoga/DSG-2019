#include "Player.h"
#include "stdafx.h"
#include "Bullet.h"
#include "Renderer.h"
#include "../3rd-party/SoundManager/SoundManager.h"

Player* Player::m_player = nullptr;

Player::Player(string name, const char* texture): Sprite(texture)
{
	setPosition(0, -0.5);
	setSize(0.1);
	setDepth(1.25);
	setColor(255, 0, 0);
	setName(name);
	m_player = this;
	m_shootingTimer.start();
}

#define SHOOTING_MIN_TIME 0.8

void Player::shoot()
{
	if (m_shootingTimer.getElapsedTime(false) > SHOOTING_MIN_TIME)
	{
		//fire animation
		Bullet* pBullet = new Bullet(m_x, m_y, "img/fire-animation-2.png");
		pBullet->setSize(0.025);
		Renderer::get()->addObject(pBullet);
		//sound
		int audioObjShoot = SoundManager::getInstance()->getAudioObjectId("snd/cannon.wav");
		SoundManager::getInstance()->play(audioObjShoot, 1.f);

		m_shootingTimer.getElapsedTime(true);//reset the timer
	}
}

Player* Player::get()
{
	return m_player;
}
