#pragma once
#include "World.h"

class Player
{
	int c_x;
	int c_y;
	int coins;
	World world;

public:
	Player(int x, int y, World world);
	~Player();

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	int getX();
	int getY();
	int getcoin();
	void addcoin();
};

