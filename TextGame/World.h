#pragma once
#include "Timer.h"
#include "Player.h"
#include <string>
using namespace std;

class World
{
	Timer m_timer;
	Player m_player1;
	Player m_player2;

	void drawMaze();
	
public:
	World(string nameFile);
	~World();

	void draw();
};