#pragma once

#include "Player.h"
#include "World.h"
#include <vector>

class GameLogic
{

	Player m_player1, m_player2;
	World m_world;
	bool ended;
	vectro<char> v;
public:
	GameLogic(Player& player1, Player& player2, World& world);
	~GameLogic();

	void processInput();
	bool gameHasEnded();
	void drawCoins();
};

