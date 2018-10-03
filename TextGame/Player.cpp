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

int Player::getScore() {
	return score;
}

void Player::addScore() {
	score=score+1;
}
