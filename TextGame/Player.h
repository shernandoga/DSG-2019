#pragma once

class Player
{
	int x, y, coins=0, limitx,limity;
public:
	Player();
	~Player();
	void setcoord(int q, int w);
	void setlimit(int q, int w);
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	bool movegeneral(int x1, int y1);
};

