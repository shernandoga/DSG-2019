#pragma once

class Player
{
	int score;

public:
	Player();
	~Player();

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	int getScore();
	void addScore();
};

