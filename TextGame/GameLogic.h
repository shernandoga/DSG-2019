#pragma once

class Player;
class World;

class GameLogic
{
	World& m_world;
	Player& m_player;
	Player& m_player2;
public:
	GameLogic(World& world, Player& player, Player& player2);
	~GameLogic();

	void processInput();
	bool gameHasEnded();
};

