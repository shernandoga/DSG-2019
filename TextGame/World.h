#pragma once
#include "Timer.h"
#include <string>
#include <vector>
using namespace std;

class World
{
	Timer m_timer;
	vector <char> m_cells;
	void updateVector(char player, char newPosition);
	int m_heigth;
	int m_width;


public:
	World(string nameFile);
	~World();

	void drawMaze();
	void draw();
	string attemptMove(int oldx, int oldy, int newx, int newy);
	vector<char>& getVector();
	int getPlayer1ROW();
	int getPlayer1COL();
	int getPlayer2ROW();
	int getPlayer2COL();
};