#include "stdafx.h"
#include "Player.h"
//Griffith !!!!!!
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
	if (this->getY()>0) 
	{c_y--;}
	setpos(c_x, c_y);

}

void Player::moveDown()
{ 
	if (this->getY() < 19)
	{c_y++; }
	setpos(c_x, c_y);
}

void Player::moveRight()
{
	if (this->getX() < 19)
	{c_x++;}
	setpos(c_x, c_y);
}

void Player::moveLeft()
{
	if (this->getX() > 0)
	{c_x--;}
	setpos(c_x, c_y);
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