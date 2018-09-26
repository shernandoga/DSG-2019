#pragma once

class Player;
class World;

class GameLogic
{

public:
	GameLogic(World& world);
	~GameLogic();

	void processInput();
	bool gameHasEnded();
};
