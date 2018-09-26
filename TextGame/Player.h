#pragma once

class Player
{
	int c_x;
	int c_y;
	int coins;

public:
	Player();
	~Player();

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	void setpos(int x, int y);
	int getX();
	int getY();
	int getcoin();
	void addcoin();

};

