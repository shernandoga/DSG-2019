#include "Player.h"
#include "stdafx.h"

Player::Player(string name, const char* texture): Sprite(texture)
{
	setPosition(0, -0.5);
	setSize(0.2);
	setDepth(1.25);
	setColor(255, 0, 0);
	setName(name);
}

