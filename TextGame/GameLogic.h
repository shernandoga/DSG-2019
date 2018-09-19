#pragma once

class Player;
class World;

class GameLogic
{
	World& m_world;
public:
	GameLogic(World& world);
	~GameLogic();

	void processInput();
	bool gameHasEnded();
};

