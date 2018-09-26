#include "stdafx.h"
#include "Player.h"
#include "World.h"


Player::Player()
{
}


Player::~Player()
{
}

void Player::setcoord(int q, int w) {
	x = q;
	y = w;

}


void Player::moveUp()
{
	//World::getInstance()->
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