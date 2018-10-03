#pragma once
#include "Timer.h"
#include <string>
#include <vector>
#include "Player.h"
using namespace std;

class World
{
	Timer m_timer;
	vector<char> m_maze;
	int m_sizeX, m_sizeY;
	Player m_player1, m_player2;

	struct point2D {
		double x, y;
	};

   #define NUM_POINTS 7

	void drawMaze();
	void ReadFile(const char* filename, point2D* points, int numPoints);
	void PrintPoints(point2D* points, int numPoints);
	void drawScore();

public:
	World(string nameFile);
	~World();

	void draw();
};