#include "stdafx.h"
#include "Player.h"

int coins;
int c_x;
int c_y;

Player::Player()
{
	coins = 0;
	c_x = 0;
	c_y = 0;

}


Player::~Player()
{
}


void Player::moveUp()
{
	c_y--;

}

void Player::moveDown()
{ 
	c_y++:
}

void Player::moveRight()
{
	c_x++;
}

void Player::moveLeft()
{
	c_x--;
}

int Player::getX() {

	return c_x;
}

int Player::getY() {

	return c_y;
}

int Player::getcoin() {

	return coins;
}

void Player::addcoin(){

	coins++;
}

void Player::setpos(int x, int y) {

	c_x = x;
	c_y = y;

}