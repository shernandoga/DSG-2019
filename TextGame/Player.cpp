#include "stdafx.h"
#include "Player.h"
#include "World.h"

Player::Player(int x,int y, World& world)
	: world(world)
{
	c_x=x;
	c_y = y;
	coins = 0;
}


Player::~Player()
{
}


void Player::moveUp()
{
	string option = world.attemptMove(c_x, c_y, c_x, c_y - 1);
	if (option == "YES") {
		c_y = c_y - 1;
	}
	else if (option == "COIN") {
		c_y = c_y - 1;
		addcoin();
	}
}

void Player::moveDown()
{ 
	string option = world.attemptMove(c_x, c_y, c_x, c_y + 1);
	if (option == "YES") {
		c_y = c_y + 1;
	}
	else if (option == "COIN") {
		c_y = c_y + 1;
		addcoin();
	}
}

void Player::moveRight()
{
	string option = world.attemptMove(c_x, c_y, c_x + 1, c_y);
	if (option == "YES") {
		c_x = c_x + 1;
	}
	else if (option == "COIN") {
		c_x = c_x + 1;
		addcoin();
	}
}

void Player::moveLeft()
{
	string option = world.attemptMove(c_x, c_y, c_x - 1, c_y);
	if (option == "YES") {
		c_x = c_x - 1;
	}
	else if (option == "COIN") {
		c_x = c_x - 1;
		addcoin();
	}
}

int Player::getX()
{
	return c_x;
}
int Player::getY()
{
	return c_y;
}
int Player::getcoin()
{
	return coins;
}
void Player::addcoin()
{
	coins = coins++;
}