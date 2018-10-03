#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	score = 0;
}


Player::~Player()
{
}


void Player::moveUp()
{
}

void Player::moveDown()
{ 
}

void Player::moveRight()
{
}

void Player::moveLeft()
{
}

void Player::addScore() {
	score = score + 1;
}

int Player::getScore() {
	return score;
}
