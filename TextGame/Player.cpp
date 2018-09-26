#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}


void Player::moveUp()
{

	if (x!=limitx) {
		x = x + 1;
	}


}

void Player::moveDown()
{ 

	if (x != 0) {
		x = x - 1;
	}
}

void Player::moveRight()
{
	if (y != limity) {
		y = y + 1;
	}
}

void Player::moveLeft()
{

	if (y != 0) {
		y = y - 1;
	}
}