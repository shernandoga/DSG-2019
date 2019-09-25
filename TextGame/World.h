#pragma once
#include "Timer.h"
#include <string>
#include <vector>
using namespace std;

class World
{
	Timer m_timer;
	vector <char> m_cells;
	void drawMaze();


public:
	World(string nameFile);
	~World();

	void draw();
	vector<char>& getVector();
	string attemptMove(int oldx,int oldy,int newx,int newy);
	void updateVector(char player,char newPosition);
};