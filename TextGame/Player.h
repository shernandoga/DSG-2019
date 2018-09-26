#pragma once

class Player
{
	int x, y, coins, limitx,limity;
public:
	Player();
	~Player();

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
};

