#pragma once
#include "Timer.h"
#include <string>
using namespace std;

class World
{
	Timer m_timer;

	void drawMaze();
	
public:
	World(string nameFile);
	~World();

	void draw();
};