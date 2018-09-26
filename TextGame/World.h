#pragma once
#include "Timer.h"
#include "Player.h"
#include <string>
#include <vector>
using namespace std;

class World
{
	Timer m_timer;
	Player player1;
	Player player2;

	int m_width = 0, m_height = 0;
	char m_blank = ' ', m_coin = ' ', m_player1 = ' ', m_player2 = ' ', m_wall = ' ';
	vector<char> m_maze;

	void drawMaze();
	
public:
	World(string nameFile);
	~World();
	void ReadFile(std::string filename);


	void draw();
};