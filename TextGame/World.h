#pragma once
#include "Timer.h"
#include <string>
#include <vector>
using namespace std;

class World
{
	Timer m_timer;
	vector<char> m_maze;
	int m_sizeX, m_sizeY;


	void drawMaze();

public:
	World(string nameFile);
	~World();

	void draw();
};