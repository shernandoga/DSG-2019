#pragma once

class Player;
class World;

class GameLogic
{

	Player player1, player2;
	World world;

public:
	GameLogic();
	~GameLogic();

	void processInput();
	bool gameHasEnded();
};

