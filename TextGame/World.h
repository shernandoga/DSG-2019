#pragma once
#include "Timer.h"
#include <string>
#include <vector>
#include "Player.h"
using namespace std;

class World
{
	static World* m_pInstance;


	Timer m_timer;
	vector<char> m_maze;
	int m_sizeX, m_sizeY;
	Player player1, player2;

	struct point2D {
		double x, y;
	};

   #define NUM_POINTS 7

	void drawMaze();
	void ReadFile(const char* filename, point2D* points, int numPoints);
	void PrintPoints(point2D* points, int numPoints);

public:
	World(string nameFile);
	~World();

	void draw();

	static World* getInstance() { return m_pInstance; }
};