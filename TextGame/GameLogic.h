#pragma once

class Player;
class World;

class GameLogic
{

public:
	GameLogic();
	~GameLogic();

	void processInput();
	bool gameHasEnded();
};

